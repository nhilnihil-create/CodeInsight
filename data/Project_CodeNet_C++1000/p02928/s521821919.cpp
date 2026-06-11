#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    ll n, k; cin >> n >> k;
    vector<int> a(n); inv(n, a);
    vector<int> v;
    ll in_a = 0, in_a_a = 0;
    rep(i, a.size()){
        ll bf = 0, af = 0;
        rep(j, a.size()){
            if(i==j) continue;
            if(i > j){ //前を見ている
                if(a[i] > a[j]) bf++;
            }else{
                if(a[i] > a[j]) af++;
            }
        }
        in_a += af;
        in_a_a += (af+bf);
    }
    ll ans = 0;
    ll mul1 = k % MOD;
    ll mul2 = (k * (k-1) / 2) % MOD;
    ans = (in_a * mul1 % MOD + in_a_a * mul2 % MOD);
    cout << ans % MOD << endl;
    return 0;   
}
