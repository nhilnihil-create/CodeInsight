//om namah shivaay
//faith over fear
//no one wants to die,yet death is the destination we all share 
// don't think you are,know you are!!

#include<bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define ll long long 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define ford(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define fora(it,x) for(auto it:x)
#define PI 3.14159265
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
 
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef long double ld;
 
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

ll a[2*100002],b[2*100002];

void fun(ll n,ll k){
    if(k==0) return;
    ll f=0;
    forn(i,n){ if(a[i]!=n){
        f=1;
        break;
    }
    }
    if(f==0) return;
    forn(i,n+1) b[i]=0;
    forn(i,n){
        b[max((ll)1,-a[i]+i+1)]+=1;
        if((a[i]+i+1+1)<=n) b[a[i]+i+2]-=1; 
    }
    for1(i,n) b[i]+=b[i-1];
    forn(i,n){
        a[i]=b[i+1];
    }
    fun(n,k-1); 
}

int main(){
    ll n,k;
    cin>>n>>k;
    forn(i,n) cin>>a[i];
    fun(n,k);
    forn(i,n) cout<<a[i]<<" ";
}