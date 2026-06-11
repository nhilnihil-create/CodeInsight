#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define OKawaiiKoto ios::sync_with_stdio(false);cin.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=2*1e18;
const ld PI=3.14159265358979323846;
int main()
{
    OKawaiiKoto
    ll l,r,d,cnt=0;
    cin>>l>>r>>d;
    for(int i=l;i<=r;i++) if(i%d==0) cnt++;
    cout<<cnt;
}
