#include<iostream>
#include<vector>
using namespace std;

void show(int arr[], int N){
	for(int i=0; i<N; i++)
		if(i<N-1)
			cout<<arr[i]<<' '<<flush;
		else
			cout<<arr[i]<<flush;
	cout<<endl;
}

int ShellSort(int*, int);
int InsertionSort_r(int*, int, int);

int main(){
	int N;
	cin>>N;

	int* arr=new int[N];

	for( int i=0; i<N; i++)
		cin>>arr[i];
	
	int cnt=ShellSort(arr, N);

	cout<<cnt<<endl;

	for( int i=0; i<N; i++)
		cout<<arr[i]<<endl;

	delete[] arr;
}


int ShellSort(int arr[], int N)
{
	vector<int> range;

	for( int g=1; g <= N;){
		range.push_back(g);
		g=g*3+1;
	}

	cout<<range.size()<<endl;
	for( int i=range.size() -1; i>=0; i--) 
		cout<<range[i]<<' '<<flush;
	cout<<endl;


	int count;
	for( int i=range.size() -1; i>=0; i-- )
		count=InsertionSort_r(arr, N, range[i]);

	return count;
}


int InsertionSort_r(int arr[], int N, int r)
{
	static int cnt=0;
	bool changed=false;
	for( int compindex=r; compindex<N; compindex++) {

		int comp= arr[compindex];

		int j=compindex - r;

		for( ; j>=0; j-=r ) {
			if(arr[j] > comp){
				arr[ j+r ]=arr[j];
				cnt++;
				changed=true;
			}
			else
				break;
		}

		arr[ j+r ] =comp;


		changed=false;
	}
	return cnt;
}
				




	
	


	