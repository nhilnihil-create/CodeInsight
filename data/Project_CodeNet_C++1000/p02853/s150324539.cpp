#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
	int n,m;
  	cin>>n>>m;
    int ans=0;	
  	if(n==1) ans+=300000;
  if(m==1) ans+=300000;
  if(n==2) ans+=200000;
  if(m==2) ans+=200000;
  if(n==3) ans+=100000;
  if(m==3) ans+=100000;
  if(n==1 && m==1) ans+=400000;
cout<<ans<<endl;
  return 0;
}