#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n; cin>>n;
	int a[n+1]={};
	int b[n]={};
	int c[n]={};
	a[n]=-1;
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];
	rep(i,n-1) cin>>c[i];
	int ans=0;
	//cout<<ans<<endl;
	rep(i,n){
		ans+=b[a[i]-1];
		//cout<<ans<<endl;
		if(a[i]+1==a[i+1]){
			ans+=c[a[i]-1];
		}
			//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
		