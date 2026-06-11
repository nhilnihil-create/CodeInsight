#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int n,x,y;cin>>n>>x>>y;x--,y--;
    vector<int>G(n-1,0);
    REP(i,n-1)rep(j,i+1,n)G[min({abs(i-j)-1,abs(i-x)+abs(j-y),abs(i-y)+abs(j-x)})]++;
    REP(i,n-1)cout<<G[i]<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}