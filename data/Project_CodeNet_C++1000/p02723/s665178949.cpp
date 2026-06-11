#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define FOR(a, b, c) for (int (a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))

int main() {
    string s;
    cin >> s;
    if (s[2] == s[3] && s[4] == s[5]) {
        cout << "Yes";
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
