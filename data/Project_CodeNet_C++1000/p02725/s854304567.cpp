#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000100];
void solve(){
	cin>>k>>n;
	int res=0;
	cin>>a[0];
	for(int i=1;i<n;++i){
		cin>>a[i];
		res=max(res,a[i]-a[i-1]);
	}
	res=max(res,k+a[0]-a[n-1]);
	cout<<k-res<<endl;
}
int main(){
	solve();
	return 0;
}