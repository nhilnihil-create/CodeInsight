#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	int p[a],q[b],r[c];
	for(int &i:p) cin>>i;
	for(int &i:q) cin>>i;
	for(int &i:r) cin>>i;
	sort(p,p+a,greater<int>());sort(q,q+b,greater<int>());
	int ans[x+y+c],top=0;
	for(int i=0;i<x;i++) ans[top++]=p[i];
	for(int i=0;i<y;i++) ans[top++]=q[i];
	for(int i:r) ans[top++]=i;
	sort(ans,ans+top,greater<int>());
	ll res=0;
	for(int i=0;i<x+y;i++) res+=ans[i];
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
