#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vll a(n);
    ll ans=0;
    rep(i,n) cin>>a[i];
    rep(i,n) ans^=a[i];
    rep(i,60){
        int cnt=0;
        rep(j,n)if(a[j]>>i&1) cnt++;
        if(cnt&1)rep(j,n) a[j]-=a[j]&(1LL<<i);
    }
    int k=0;
    RFOR(i,59,0){
        bool find=false;
        FOR(j,k,n-1)if(a[j]>>i&1){
            swap(a[k],a[j]);
            find=true;
            break;
        }
        if (!find) continue;
        rep(j,n)if(j!=k && a[j]>>i&1){
            a[j]^=a[k];
        }
        k++;
    }
    ll sum=0;
    rep(i,n) sum^=a[i];
    ans+=sum*2;
    cout<<ans<<"\n";
    return 0;
}
