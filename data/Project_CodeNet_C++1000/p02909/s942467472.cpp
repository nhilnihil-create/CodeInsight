#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S == "Sunny") {
        cout << "Cloudy" << endl;
    } else if (S == "Cloudy") {
        cout << "Rainy" << endl;
    } else {
        cout << "Sunny" << endl;
    }
    return 0;
}
