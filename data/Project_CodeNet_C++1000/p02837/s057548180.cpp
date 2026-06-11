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
#define  setbit(x)  __builtin_popcountll(x)
#define  deb2(x,y)   cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define  rep(i,a,b)  for(int i=a ; i<b ; ++i)
#define  repr(i,a,b)  for(int i=a ; i>=b ; --i)
 
#define PI 3.141592653589793
const ll p = 5;
const ll INF = 1000000000;
const ll MAX_N = 2e5 + 2;

void solve(){
    int t; cin >> t;
    vector<pair<int,int>>adj[t+2];
    
    int n,p,s;
    rep(i,1,t+1){
        cin >> n;
        rep(j,0,n){
            cin >> p >> s;
            adj[i].pb({p,s});
        }
    }
    
    int range = (1<<t),ans = 0;
    rep(i,0,range){
        int j = 0, num = i;
        vi v(t);
        while(num && j<t){
            v[j] = (num&1);
            num >>= 1 , ++j;
        }
        bool flag = true;
        
        for(int k=0;k<t;++k){
            if(v[k] == 0) continue;
            for(auto x:adj[k+1]){
                int person = x.first, status = x.second;
                if(v[person-1] != status){
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag) ans = max(ans , accumulate(all(v),0));
    }
    
    cout << ans;
}

int main() {
    IOS;
    // int t; cin >> t;
    int t = 1;
    while(t--) solve();
}