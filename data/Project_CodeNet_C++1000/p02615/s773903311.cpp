#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void swap(long long *a,long long *b){
	long long temp = *a;
	*a = *b;
	*b = temp;
}

int partition(long long l,long long h,long long arr[]){
		long long index = l;
		long long temp = arr[h];
		for(long long i=l;i<h;i++){
			if(arr[i]>=temp){
				swap(&arr[index],&arr[i]);
				index++;
		}
	}
		swap(&arr[index],&arr[h]);
		return index;
			}



void quickSort(long long arr[],long long l,long long h){
	
	if(l<h){
		int index = partition(l,h,arr);
		quickSort(arr,l,index-1);
		quickSort(arr,index+1,h);
	}
}

//long long arr[1000000];

int main(){

	long long n; cin>> n;
	vector<int>arr(n);
	
	for(int i=0;i<n;i++)cin >> arr[i];

		sort(arr.begin(),arr.end(),greater<int>());
//for(int i=0;i<n;i++)printf("%lli ",arr[i]);


	long long comfort = arr[0];

	int temp = n-2;
	if(temp%2){
		
		for(int i=1;i<=(temp/2);i++)comfort += 2 * arr[i];
		comfort += arr[(temp/2) + 1];
	}
	else{
		for(int i=1;i<=(temp/2);i++)comfort += 2 * arr[i];
	}

	printf("%lli\n",comfort);




	return 0;
}