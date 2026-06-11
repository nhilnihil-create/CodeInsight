#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>
#include <new>

//#include "All.h"

using namespace std;

#define EPS (1e-9)
#define INF (1e9)
#define MOD (ll)(1e9 + 7)
#define PI (acos(-1))
#define REP(i,a,n) for(int i=a;i<n;i++)
#define rep(i, n) REP(i,0,n)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" ; "IMPOSSIBLE")

using ll = long long int;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    rep(i, b) tmp *= a;
    return tmp;
}

int N;

int main() {
    cin >> N;
    int n = N % 10;
    switch (n) {
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
        cout << "hon" << endl;
        break;
    case 0:
    case 1:
    case 6:
    case 8:
        cout << "pon" << endl;
        break;
    case 3:
        cout << "bon" << endl;
        break;
    }
}

/*
10 5
0 -1 -2 -3 -4 -5 6 7 8 9

8 5
-1 -2 -3 -4 -5 6 7 8
*/