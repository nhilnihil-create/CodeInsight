#include <bits/stdc++.h>
//#include <random>
//#include <chrono>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define MotoHaiyaku ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=2*1e18;
const ld PI=3.14159265358979323846;
int main()
{
    MotoHaiyaku
    ll h,w,k,ans=0,t=0;
    string s[10];
    cin>>h>>w>>k;
    rep(i,h) cin>>s[i];
    rep(i,h) rep(j,w) if(s[i][j]=='#') t++;
    rep(i,1<<h)
    {
        rep(j,1<<w)
        {
            ll a=i,b=j;
            set<pair<ll,ll> > st;
            rep(x,h)
            {
                if(a%2)
                {
                    rep(y,w)
                    {
                        if(s[x][y]=='#') st.insert(mp(x,y));
                    }
                }
                a/=2;
            }
            rep(y,w)
            {
                if(b%2)
                {
                    rep(x,h)
                    {
                        if(s[x][y]=='#') st.insert(mp(x,y));
                    }
                }
                b/=2;
            }
            if(t-st.size()==k) ans++;
        }
    }
    cout<<ans;
}
