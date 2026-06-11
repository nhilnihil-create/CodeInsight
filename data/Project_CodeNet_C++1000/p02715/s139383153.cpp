#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

ll table[100005];

ll modpow(ll n, ll k, ll mod){
    ll rtn = 1;
    while(k > 0){
        if(k&1) rtn = rtn*n%mod;
        n = n * n % mod;
        k >>= 1;
    }
    return rtn;
}

int main(){
    int n, k;
    cin >> n >> k;
    ll dp[k+1];
    ll ans = 0;
    for(int i = k ; i >= 1 ; i--){
        ll a = modpow(k/i, n, mod); 
        for(int j = 2 ; i*j <= k ; j++){
          if(a - table[i*j]<0) a = a + mod - table[i*j];
          else a -= table[i*j];
        }
        table[i] = a;
        ans += a*i;
        ans %= mod;
    }
    cout << ans%mod << endl;
    
}