#include<bits/stdc++.h>
using namespace std;
long long A[200005]={0};
long long B[200005]={0};
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) cin>>A[i];
	for(int i=1; i<=m; i++) cin>>B[i];
	for(int i=1; i<=n; i++) A[i]+=A[i-1];
	for(int i=1; i<=m; i++) B[i]+=B[i-1];
	long long ret = 0;
	for(int i=0; i<=n; i++){
		if(A[i]>k) break;
		long long read = i;
		read+=(upper_bound(B+1,B+m+1,k-A[i])-B-1);
		ret = max(ret,read);
	}
	cout<<ret;
}