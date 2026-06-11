#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <cassert>
#include <memory>
using namespace std;
typedef long long ll;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    ll N;
    cin >> N;

    set<ll> div;
    for (ll i = 1LL; i * i <= N; i++) {
        if (N % i == 0) {
            div.insert(i);
            div.insert(N / i);
        }    
    }

    ll ans = 0;
    for (auto x: div) {
        if (x == 1) continue;
        ll xt = N;
        while (xt % x == 0) {
            xt /= x;
        }
        if (xt % x == 1) {
            ans++;
        }
    }

    set<ll> div2;
    for (ll i = 1LL; i * i <= (N - 1); i++) {
        if ((N - 1) % i == 0) {
            div2.insert(i);
            div2.insert((N - 1) / i);
        }
    }

    ans += (div2.size() - 1);

    cout << ans << endl;

    return 0;
}
