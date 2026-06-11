#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);++i)
#define REP(i,n) for (int i=0;i<=(n);++i)
#define all(x) (x).begin(), (x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
const int INF = 10000000;

ll modpow(ll m, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1){                  //奇数の場合
            res = res * m % mod;
        }
        m = m * m % mod;
        n >>= 1;                    //累乗の数を2で割ってる
    }
    return res;

}

int main() {
    ll m, n;
    cin >> m >> n;
    cout << modpow(m, n, 1000000007) << endl;
}
