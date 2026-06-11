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

ll fac[4004], inv[4004], finv[4004];

void SetTable(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i = 2 ; i <= 4002; i++){
        fac[i] = (fac[i-1]*i)%mod;
        inv[i] = mod - (inv[mod%i])*(mod/i)%mod;
        finv[i] = (finv[i-1]*inv[i])%mod;
    }
}

ll com(ll n, ll k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return (((fac[n] * finv[k])%mod)*finv[n-k])%mod; 
}

int main(){
    SetTable();
    int n, k;
    cin >> n >> k;
    srepn(i,1,k) cout << com(n-k+1, i) * com(k-1,i-1) % mod << endl;
}