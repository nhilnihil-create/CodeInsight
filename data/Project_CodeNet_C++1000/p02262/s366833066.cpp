#include<iostream>
using namespace std;

void show(int arr[], int N){
	for(int i=0; i<N; i++)
		if(i<N-1)
			cout<<arr[i]<<' '<<flush;
		else
			cout<<arr[i]<<flush;
	cout<<endl;
}


void swap(int& a, int& b){
	int t=a;
	a=b;
	b=t;
}


int ShellSort(int* arr, int N);
int InsertionSort_r(int* arr, int N, int r);

int main()
{
	int N;cin>>N;

	int* arr= new int[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	int count=ShellSort(arr, N);

	cout<<count<<endl;

	for( int i=0; i<N; i++)
		cout<<arr[i]<<endl;

	delete[] arr;
}


int ShellSort(int* arr, int N)
{
	int counter=0;




	int* range= new int[N];  //range= { 1, 4, 13, 40 ...}


	range[0] = 1;

	int i;
	for( i=1; range[i-1]*3+1 < N; i++){
		range[i] = range[ i-1 ]*3+1;
	}
	int range_len =i; //range ?????????????????§????????\??£????????????

	
	cout<<range_len<<endl;

	for( int i=1; range_len - i >=0; i++ )
		cout<<range[ range_len - i ]<<' '<<flush;
	cout<<endl;







	 

	for( int i=0; range_len -i -1 >=0; i++) 
		counter=InsertionSort_r(arr, N, range[ range_len - i -1 ]);
	
	
	return counter;

	delete[] range;
	
	



	
}

int InsertionSort_r(int arr[], int N, int r)
{

	static int counter=0;
	int compindex;
	int comp;
	int j;
	bool changed=false; //??????????????¨???????????¨.??????????????????????????????????????????????????????????????????

	
	for( int i=0; i<r; i++) {


		for( int compindex=N- r -1 -i; compindex> -1; compindex-=r ){
			
			comp=arr[compindex];
			j=r;
			for( ; compindex+j<N; j+=r ){

				if(comp > arr[compindex+j]){
					arr[compindex + j -r] = arr[compindex + j];
					counter++;
					changed =true;
				}
				else
					break;
				
			}
			arr[compindex + j - r] = comp;

		
			changed=false;


		}
	}


	return counter;



	
}