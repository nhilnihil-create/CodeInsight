#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)break;
		int a[n];
		rep(i,n)cin>>a[i];
		sort(a,a+n);
		int ans=1000000;
		rep(i,n-1)ans=min(ans,a[i+1]-a[i]);
		cout<<ans<<endl;
	}
	return 0;
}
