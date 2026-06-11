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

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    string s; cin>>s;
    vi a(n);
    rep(i,n) a[i] = s[i]-'1';
    bool flg=false;
    rep(i,n)if(a[i]==1) flg=true;
    if (!flg)rep(i,n) a[i]/=2;
    rep(i,n) a[i]%=2;
    auto f=[](int n){
        int ret=0;
        while(n/=2) ret+=n;
        return ret;
    };
    int ans=0;
    rep(i,n){
        if (a[i]==0) continue;
        int x = f(n-1)-f(n-i-1)-f(i);
        ans = (x==0)? (ans+1)%2 : ans;
    }

    if (!flg) ans*=2;
    cout<<ans<<"\n";
    return 0;
}
