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

string S;
ll Smod[200010] = {};
//ll Bmod[200010] = {};
ll T[200010] = {};
const ll mod = 2019;
ll ans = 0;

int main() {
    cin >> S;
    const ll N = S.length();
    Smod[N] = 0;
    T[Smod[N]]++;
    //cout << T[Smod[N]] << endl;
    //Bmod[N] = 1;
    ll Bmod = 1;
    for (int i = N - 1; i >= 0; i--) {
        
        Smod[i] = (Smod[i + 1] + Bmod * (S[i] - '0')) % mod;
        Bmod = (Bmod * 10) % mod;

        T[Smod[i]]++;
        //cout << Smod[i] << endl;
    }
    rep(i, 2019) {
        ans += T[i] * (T[i] - 1) / 2;
    }
    cout << ans << endl;
}