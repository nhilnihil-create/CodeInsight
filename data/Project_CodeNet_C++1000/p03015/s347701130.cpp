#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 1e5+5;
const ll M = 1e9+7;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
ll qpow(ll a,ll b) {ll s=1;while(b){if(b&1)s=(s*a)%M;a=(a*a)%M;b>>=1;}return s; }
char s[maxn];
ll fac[maxn],inv[maxn];
void init()
{
    int n = 1e5+2;
    fac[0] = 1;
    rep(i,1,n) fac[i] = fac[i-1]*i%M;
    inv[n] = qpow(fac[n],M-2);
    per(i,n-1,0) inv[i] = inv[i+1]*(i+1)%M;
}
ll C(int a,int b) {return fac[a]*inv[b]%M*inv[a-b]%M;}
int main()
{
    fastio();
    init();
    cin>>s+1;
    int n = strlen(s+1);
    ll ans = 0;
    int cnt = 0;
    rep(i,1,n){
        if(s[i]=='1') ans = (ans + qpow(2,cnt)*qpow(3,n-i)%M)%M,cnt++;
    }
    ans = (ans + qpow(2,cnt))%M;
    cout<<ans<<endl;
    return 0;
}
