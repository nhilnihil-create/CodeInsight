#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

set<int> s;

// aとbの最大公約数を求める関数
template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 約数を列挙する関数
bool CalcDivisor(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != 1 && s.count(i)) return false;
            s.insert(i);
            if (i * i != n) {
                if (n/i != 1 && s.count(n / i)) return false;
                s.insert(n / i);
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int all_gcd = a[0];
    rep(i, n - 1) {
        all_gcd = gcd(all_gcd, a[i + 1]);
    }

    bool is_pair_prime = true;
    rep(i, n) {
        bool is_ok = CalcDivisor(a[i]);
        if (!is_ok) {
            is_pair_prime = false;
            break;
        }
    }

    if (all_gcd == 1) {
        if (is_pair_prime) {
            cout << "pairwise coprime" << endl;
        }
        else {
            cout << "setwise coprime" << endl;
        }
    }
    else {
        cout << "not coprime" << endl;
    }
    return 0;
}
