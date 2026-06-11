#include <bits/stdc++.h>
using namespace std;

long long n,m,q;
long long a[55],b[55],c[55],d[55];
long long ans,sum;
long long A[11];

void dfs(int i){
	if(i==n){
		long long sum=0;
		for(int j=0;j<q;j++){
			if(A[b[j]]-A[a[j]]==c[j]) sum+=d[j];
		}
		ans=max(ans,sum);
		return;
	}
	for(int j=A[i];j<=m;j++){
		A[i+1]=j;
		dfs(i+1);
	}
}

int main() {
	cin >> n >> m >> q;
	for(int i=0;i<q;i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	A[0]=1;
	dfs(0);
	cout << ans << endl;
	return 0;
}
