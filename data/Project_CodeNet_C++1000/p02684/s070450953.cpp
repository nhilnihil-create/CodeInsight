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

ll modPow(ll x, ll a) {
    if (a == 1) return x;
    if (a % 2) return (x * modPow(x, a - 1)) % MOD;
    ll t = modPow(x, a / 2);
    return ((t % MOD) * (t % MOD)) % MOD;
}

ll modInv(ll x) {
    return modPow(x, MOD - 2);
}

ll N, K;
vector<ll> A(200010, 0);
vector<ll> arv(200010, 0);

int main() {
    cin >> N >> K;
    REP(i, 1, N + 1) cin >> A[i];

    //arv[Ai]はAi町の到着順がarv[Ai]であることを行っている
    ll cnt = 1;
    arv[1] = cnt;
    ll ind = 1;

    while (true) {
        //cnt番目に着く
        cnt++;
        if (arv[A[ind]] != 0) {
            //もう着いたことある
            //初めてでたのはarv[A[ind]]で二回目の順番はind
            break;
        }
        else {
            //次の場所を
            arv[A[ind]] = cnt;

            ind = A[ind];
            
            //cout << cnt << " " << ind << endl;
            
            
            if (cnt == K) {
                cout << A[ind] << endl;
                return 0;
            }
        }
    }
    K++;
    //cout << "cnt:" << cnt << endl;
    //cout << "arv:" << arv[A[ind]] << endl;
    ll T = cnt - arv[A[ind]];
    K -= arv[A[ind]];
    K %= T;
    K += arv[A[ind]];

    //cout << "K:" << K << endl;

    auto it = find(arv.begin(), arv.end(), K);
    auto wanted_index = distance(arv.begin(), it);
    cout << wanted_index << endl;

    //REP(i, 1, N + 1) {
    //    cout << A[i] << endl;
    //}
}

/*
4 2
2 3 4 2

1 2 3 4 2 3 4

T == 3
arv[A[ind]] == 2
cnt == 5

K == 1, 2, 3,...のとき
ans == 1, 2, 3, 4, 2, 3, 4

K -= arv[A[ind]];
K %= T;
K += arv[A[ind]];
*/