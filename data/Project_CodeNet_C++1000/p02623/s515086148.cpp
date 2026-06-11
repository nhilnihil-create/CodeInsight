#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	int n,m,k;
	cin>>n>>m>>k;
	ll a[n+1],b[m+1];
	a[0]=0;b[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=m;i++) cin>>b[i],b[i]+=b[i-1];
	int x=0,y=m,ans=0;
	while(y>=0){
		while(b[y] > k) y--;
		while(x<=n && a[x]+b[y] <= k) x++;
		ans=max(ans,x-1+y);
		y--;
	}
	return ans;
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
