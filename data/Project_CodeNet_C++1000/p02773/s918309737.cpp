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
#define MOD (1e9 + 7)
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
string S[200010];
vector<string> s[200010];

int main() {

    cin >> N;
    rep(i, N) {
        string T;
        cin >> T;
        S[i] = T;
    }
    
    sort(S, S + N);

    S[N] = "";

    int a = 1;
    int a_max = a;

    REP(i, 1, N + 1) {
        
        if (S[i] == S[i - 1]) {
            a++;
        }
        else {
            a_max = max(a_max, a);
            s[a].push_back(S[i - 1]);
            a = 1;
        }

    }
    for (int i = 0; i < s[a_max].size(); i++) {
        cout << s[a_max][i] << endl;
    }
}