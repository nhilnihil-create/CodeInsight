#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define ll long long
int main(){
	ll a,b,x; cin>>a>>b;
	while(b--) cin>>x,a-=x;
	if(a<=0) cout<<"Yes"; else cout<<"No";
}
