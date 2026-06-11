#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll MOD = 1000000007;
    int N, M;
    cin >> N >> M;
    vector<int> s(N);
    vector<int> t(M);
    rep(i, N) cin >> s[i];
    rep(i, M) cin >> t[i];
    vector<vector<ll>> v(N + 1);
    vector<vector<ll>> sum(N + 1);
    rep(i, N + 1) {
        v[i].resize(M + 1);
        sum[i].resize(M + 1);
        rep(j, M + 1) {
            v[i][j] = 0;
            sum[i][j] = 0;
        }
    }
    repi(i, 1, N + 1) {
        ll buf = 0;
        repi(j, 1, M + 1) {
            if (s[i - 1] != t[j - 1]) v[i][j] = 0;
            else v[i][j] = (1 + sum[i - 1][j - 1]) % MOD;
            buf += v[i][j];
            buf %= MOD;
            sum[i][j] = (sum[i - 1][j] + buf) % MOD;
        }
    }
    cout << 1+sum[N][M] << endl;
    return 0;
}

