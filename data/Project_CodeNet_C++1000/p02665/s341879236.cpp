#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> prl;
typedef vector<ll> vcl;
typedef map<ll,ll> mapl;
typedef unordered_map<ll,ll> umap;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

int main() {
    // your code goes here
    ll n,a[100005]={0},b[100005],c[100005],pv,ans=0;
  	bool ok=false;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n){
        if(i==0){
            if(a[i]>1){
                cout << -1 << endl;
                return 0;
            }
            b[0]=1;
        } else {
        	if(ok) b[i]=2*1e17;
            else b[i]=(b[i-1]-a[i-1])*2;
          	if(b[i]>=1e17) ok=true;
            if(a[i]>b[i]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    b[n+1]=1;
    repr(i,n,0){
        if(i==n){
            c[i]=a[i];
        } else {
            c[i]=c[i+1]+a[i];
        }
    }
    c[n+1]=0;
    rep(i,0,n+1){
        if(b[i]>c[i]){
            pv=i;
            break;
        }
    }
    rep(i,0,n){
        if(i<pv){
            ans+=b[i];
        } else {
            ans+=c[i];
        }
    }
    cout << ans << endl;
    return 0;
}