#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long int A[n];
	for (int i=0; i<n; i++){
		cin>>A[i];
	}
	long long int sum = 0;
	for (int i=1; i<n; i++){
		if(A[i - 1] > A[i]){
			sum += (A[i - 1] - A[i]);
			A[i] = A[i - 1];
		}
	}
	cout<<sum;
}