#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int mypow(int X, int n) {  // 繰り返し２乗法　計算量log(n)
    if(n == 0) return 1;
    int Y = mypow(X, n/2);
    if(n % 2 == 1) return X * Y % 13 * Y % 13;
    else return Y * Y % 13;
}

int main() {
    int n; cin >> n;
    vector<ll> A(n);
    ll s = 0; ll t = 0;
    rp(i, 0, n) {
        ll a;
        scanf("%lld", &a);
        s += a;
        A[i] = a;
        if(i%2==1) t += a;
    }
    ll x = s - t*2;
    printf("%lld ", x);
    rp(i, 0, n-1) {
        x = A[i] * 2 - x;
        printf("%lld ", x);
    }
    printf("\n");
    return 0;
}
