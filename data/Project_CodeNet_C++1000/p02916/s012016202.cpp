#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n, pts=0; cin>>n;
	int A[n], B[n], C[n-1];
	for(int i=0; i<n; i++)cin>>A[i];
	for(int i=0; i<n; i++)cin>>B[i];
	for(int i=0; i<n-1; i++)cin>>C[i];
	
	for(int i=0; i<n-1; i++){
		pts+=B[A[i] - 1];
		if(A[i+1]-A[i]==1){
			pts+=C[A[i]-1];
		}
	}
	cout<<pts+B[A[n-1]-1]<<endl;
}
