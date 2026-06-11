#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long int ll;
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define  ff          first
#define  ss          second
#define  pb          push_back
#define  IOS         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  lb          lower_bound
#define  ub          upper_bound
#define  D2(x)       { cerr << "[" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }
#define  all(x)      (x).begin(), (x).end()
#define  mem(a)      memset(a , 0 ,sizeof a)
#define  deb(x)      cout << #x << " - " << x << "\n";
#define  ps(x,y)     fixed<<setprecision(y)<<x
#define  setbit(x)   __builtin_popcount(x)
#define  deb2(x,y)   cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define  rep(i,a,b)  for(int i=a ; i<b ; ++i)
#define  repr(i,a,b)  for(int i=a ; i>=b ; --i)
 
#define PI 3.141592653589793
const ll INF = 1000000000;
const ll MAX_N = 2e5 + 2;
const ll MOD = 1e9 + 7;

void solve(){
    ll n,k; cin >> n >> k;
    
    ll sum = 0,temp,mx,mn;
    vll pre(n+2,0);
    
    rep(i,2,n+2){
        pre[i] = (pre[i-1] + (i-1)) % MOD;
    }
    // D2(pre);
    rep(i,k,n+2){
        mx = (pre[n+1] - pre[n-i+1] + MOD) % MOD;
        mn = pre[i];
        temp = (mx - mn + MOD) % MOD;
        sum = (sum + temp + 1)%MOD;
    }
    cout << sum%MOD;
}

int main() {
    IOS;
    // int t; cin >> t;
    int t = 1;
    while(t--) solve();
}