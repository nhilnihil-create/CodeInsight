#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
#define pll pair<ll,ll>
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    rep(i,0,n)cin>>a[i];
    if(k>=4*log2(n))rep(i,0,n)cout<<n<<" ";
    else{
        rep(j,1,k+1){
            vector<ll> b(n+5,0);
            rep(i,0,n){
                ll l=max((ll)0,i-a[i]);
                ll r=min(n-1,i+a[i]);
                b[l]++;
                if(r<n)b[r+1]--;
            }
            rep(i,0,n)b[i+1]+=b[i];
            a=b;
            if(j==k)rep(i,0,n)cout<<b[i]<<" ";
        }
    }
}

