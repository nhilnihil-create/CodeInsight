#include<iostream>
#include<vector>
using namespace std;

int out(vector<int> &A,int n,int k){
	int i;
	for (i=0;i<=n-2;i++){
		if(i==k){
			cout << "["<< A[i] <<"] ";
		}else{
			cout << A[i] <<" ";
		}
		
	}
	cout << A[n-1] <<endl;
}

int partition(vector<int> &A, int p, int r){
	int x=A[r];
	int i=p-1;
	int j;
	for (j=p;j<r;j++){
		if (A[j]<=x){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> A(n);
	int i;
	for (i=0;i<n;i++){
		cin >> A[i];
	}
	
	int k=partition(A,0,n-1);
	out(A,n,k);
	return 0;
}