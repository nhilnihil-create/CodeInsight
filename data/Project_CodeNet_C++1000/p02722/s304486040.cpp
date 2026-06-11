#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

int main() {
    ll N;
    cin >> N;
    
    set<ll> ans;
    for (ll i = 1; i * i <= N; ++i) {
        if ((N - 1) % i == 0) {
            if (i != 1) ans.insert(i);
            if ((N - 1) / i != 1) ans.insert((N - 1) / i);
        }
    }
    vector<ll> S;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            S.push_back(i);
            S.push_back(N / i);
        }
    }
    for (ll x : S) {
        if (x == 1) continue;
        ll n = N;
        while (n % x == 0) n /= x;
        if ((n - 1) % x == 0) ans.insert(x);
    }
    cout << SZ(ans) << "\n";
    return 0;
}
