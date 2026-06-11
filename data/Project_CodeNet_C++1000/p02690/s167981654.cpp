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


struct Room {
    int id, mark, step;
    vector<int> vicinities;
};

int main() {
    int X; cin >> X;
    for (int i = 1; i < 10000; i++) {
        for (int j =0; j <= i; j++) {
            ll A = j;
            for (int s = -1; s <= 1; s += 2) {
                ll B = s*(i - j);
                if (A * A * A * A * A - B * B * B * B * B == X) {
                    cout << A << " " << B << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

