#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>>adj(n+1);
    int maxi = (n-1)*(n-2)/2;
    for(int i = 2;i<=n;i++){
        adj[1].push_back(i);
    }
    if(k>maxi){
        cout << -1;
        return;
    }
    int cnt = 0;bool ok = 0;
    for(int i = 2;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(cnt==maxi-k){ok = 1;break;}
            adj[i].push_back(j);
            cnt++;
        }
        if(ok) break;
    }
    int siz = 0;
    for(int i = 1;i<=n;i++) siz += adj[i].size();
    cout << siz <<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<adj[i].size();j++){
            cout << i <<' ' << adj[i][j] <<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}