#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <regex>
#include <sstream>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int st, ed;
    st = h1 * 60 + m1;
    ed = h2 * 60 + m2;

    if (ed - st - k >= 0)
        cout << ed - st - k << endl;
    else
        cout << 0 << endl;

    return 0;
}
