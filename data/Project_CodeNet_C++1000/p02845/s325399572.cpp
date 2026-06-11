#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10, MOD = 1e9 + 7;



int main()
{
    fastInp;

    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    vector<ll> cnt(n);

    ll ans = 1, t = 3;

    for (int i = 0; i < cnt.size(); i++) {
        cnt[vec[i]]++;
        if (vec[i] == 0) {
            ans *= t;
            t--;
        } else {
            ans *= cnt[vec[i] - 1];
            cnt[vec[i] - 1]--;
        }
        ans %= MOD;
    }

    cout << (ans) % MOD;

    return 0;
}