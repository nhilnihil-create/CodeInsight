#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


vector<pair<ll, int>> prime_factorize(ll n) {
    vector < pair < ll, int >> res;
    int num = 0;
    while (n % 2 == 0) {
        num++;
        n /= 2;
    }
    if (num != 0) res.emplace_back(make_pair( 2, num ));

    for (ll p = 3; p * p <= n; p += 2) {
        num = 0;
        while (n % p == 0) {
            num++;
            n /= p;
        }
        if (num != 0) res.emplace_back(make_pair(p, num));
    }
    if (n != 1)res.emplace_back(make_pair(n, 1));
    return res;
}

int main() {
	ll N, ans=0;
	cin >> N;
    auto list = prime_factorize(N);
    for (const auto& a : list) {
        for (int k = 1; a.second >= k * (1 + k) / 2; k++) {
            ans++;
        }
    }
    cout << ans << endl;
}
