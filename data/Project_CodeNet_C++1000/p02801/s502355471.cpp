#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define FOR(a, b, c) for (int (a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int (a) = (c) - 1; (a) >= (b); --(a))
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))

int main() {
    char c;
    cin >> c;
    cout << char(c + 1) << endl;
    return 0;
}
