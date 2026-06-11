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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(char i = '0';i<='9';i++){
        for(char j = '0';j<='9';j++){
            for(int k = '0';k<='9';k++){
                bool oki = 0,okj = 0,okk = 0;
                for(int z = 0;z<n;z++){
                    if(s[z]==i&&oki==0) {oki = 1;continue;}
                    if(s[z]==j&&oki==1&&okj==0) {okj = 1;continue;}
                    if(s[z]==k&&oki==1&&okj==1&&okk==0){okk = 1;continue;}
                }
                if(oki&&okj&&okk) ans++;
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}