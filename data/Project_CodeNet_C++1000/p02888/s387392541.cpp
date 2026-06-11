#include <iostream>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}


int main(){
	
	int N;
	cin>>N;
	int arr[N];
	int count = 0;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
	}

  	qsort(arr,N,sizeof(int),compare);

    for(int i=0; i<N; i++)
    {
    	int k = i+2;
    	for(int j=(i+1); j<N; j++)
    	{
    		while(k<N && (arr[i]+arr[j] > arr[k]))
    		{
    			k++;
    		}
    		count = count + k - j -1;
    	}
    }
    cout<<count;
    return 0;
}