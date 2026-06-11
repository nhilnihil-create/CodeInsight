#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int a,b,c,k;cin>>a>>b>>c>>k;
    int cnt=0;
    while(a>=b&&cnt<k)b*=2,cnt++;
    while(b>=c&&cnt<k)c*=2,cnt++;
    cout<<(a<b&&b<c?"Yes":"No")<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}