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
    string t;
    cin >> t;

    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '?')
            t[i] = 'D';
    }

    cout << t << endl;

    return 0;
}
