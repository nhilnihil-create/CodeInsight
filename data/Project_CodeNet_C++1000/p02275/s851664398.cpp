#include<iostream>
using namespace std;

#define MAX_LEN 2000000
#define MAX_VAL 100001

void countingSort(int n,int A[],int B[], int C[]){
	int i;
	for(i=0;i<=MAX_VAL;i++){
		C[i]=0;
	}
	for(i=0;i<n;i++){
		C[A[i]]++;
	}
	for(i=1;i<=MAX_VAL;i++){
		C[i]=C[i]+C[i-1];
	}

	for(i=n-1;i>=0;i--){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
}

int main(){
	
	int n, A[MAX_LEN],B[MAX_LEN],C[MAX_VAL+1];
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}

	countingSort(n,A,B,C);
	
	cout << B[0];
	for(int i=1;i<n;i++){
		cout << " " << B[i];
	}
	cout << endl;

	return 0;
}

