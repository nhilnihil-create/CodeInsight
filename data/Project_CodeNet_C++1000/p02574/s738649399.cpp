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

int max_a = 1000001;

// aとbの最大公約数を求める関数
template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(max_a);
    rep(i, n) {
        cin >> a[i];
        c[a[i]]++;
    }

    int all_gcd = 0;
    rep(i, n) all_gcd = gcd(all_gcd, a[i]);
    if (all_gcd > 1) {
        cout << "not coprime" << endl;
        return 0;
    }

    for (int i = 2; i < max_a; i++) {
        int cnt = 0;
        for (int j = i; j < max_a; j += i) {
            cnt += c[j];
        }
        if (cnt > 1) {
            cout << "setwise coprime" << endl;
            return 0;
        }
    }

    cout << "pairwise coprime" << endl;
    return 0;
}
