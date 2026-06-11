#include<iostream>
using namespace std;

#define MAX_LEN 2000000
#define MAX_VAL 10000

void countingSort(int n,int A[],int B[], int C[]){
	int i;
	for(i=0;i<MAX_VAL;i++){
		C[i]=0;
	}
	for(i=0;i<n;i++){
		C[A[i]]++;
	}
	
	int idx=0;
	for(i=0;i<MAX_VAL;i++){
		if(C[i]==0) continue;
		for(int j=0;j<C[i];j++){
			B[idx++]=i;
		}
	}
}

int main(){
	
	int n, A[MAX_LEN],B[MAX_LEN],C[MAX_VAL];
	
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

