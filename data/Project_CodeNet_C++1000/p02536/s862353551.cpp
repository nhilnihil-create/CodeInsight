#include <bits/stdc++.h>
using namespace std;
#define     ff first
#define     ss second
#define     ll long long
#define     ld long double
#define     pb push_back
#define     endl "\n"
#define     MOD 1000000007
#define     INF 1e18
#define     mod 998244353
#define     MAXN 10000001
#define     REP(i,n) for(ll i=0;i<(n);i++)
#define     PER(i,n) for(ll i=n-1;i>=0;i--)
#define     FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define     FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define     all(x) x.begin(),x.end()
#define     FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     BLOCK 555
mt19937     rng(chrono::steady_clock::now().time_since_epoch().count());
typedef     pair<ll, ll> pl;
typedef     vector<ll> vll;
typedef     vector<string> vs;
typedef     vector<pl> vp;
typedef     vector<vector<ll>> vvll;


/*      author:- Indrajit Sen
        Institution:- Jalpaiguri Government Engineering College
        id:- @Is97, @indra1997
                                                                
                                                                
*/


// directions for matrix movement
vll dir_x{0ll, 0ll, -1ll, 1ll};
vll dir_y{1ll, -1ll, 0ll, 0ll};

// log(y) power calculation
ll power_mod(ll x, ll y, ll m){
    ll arr = 1;
    x%=m;
    while(y){
        if(y&1){
            arr=(arr*x)%m;
        }
        y>>=1;
        x=(x*x)%m;
    }
    return arr;
}

ll power(ll x, ll y){
    ll arr = 1;
    while(y){
        if(y&1){
            arr*=x;
        }
        y>>=1;
        x = x*x;
    }
    return arr;
}


ll mod_inv(ll x,ll m){
    return power_mod(x,m-2,m);
}

bool comp(const pair<ll,pair<ll,ll>> &a, const pair<ll,pair<ll,ll>> &b) { 
    if(a.ff == b.ff){

        return (a.second < b.second); 
    }
    return (a.ff < b.ff); 
} 

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

bool isPalindrome(string s){
    bool flag = true;
    for(ll i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}

bool isPerfectSquare(ll n){
    ld val = sqrt(n);
    return(val-floor(val) == 0);
}

bool isPrime(ll n){
    if(n<2){
        return false;
    }
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

ll NCR(ll n, ll k){ 
    ll res = 1;
    if ( k > n - k ){
        k = n - k;  
    }
    REP(i,k){
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
} 

ll cntBits(ll n){
    ll cnt = 0;
    for(ll i=0;i<64;i++){
        if((1ll<<i)&n){
            cnt++;
        }
    }
    return cnt;
}

vll adj[100005];
vector<bool> vis(100005, false);

void dfs(ll node){
    vis[node] = true;
    for(ll child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
  
void solve(){

    ll n,m;
    cin>>n>>m;
    ll u,v;
    REP(i,m){
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll c = 0;
    REP(i,n){
        if(!vis[i]){
            dfs(i);
            c++;
        }
    }
    cout<<c-1<<endl;

}

int main(){

    FIO;
    // ll t;
    // cin>>t;
    // FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    // }
    return 0;
}
