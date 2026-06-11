#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <complex>
#include <numeric>
#include <string.h>
#include <random>
#include <cmath>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int N;
int X[300000];
int S[300000];
int nxt[300000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,N) {
        int A; cin >> A; A--;
        X[A]++;
    }
    sort(X, X+N, greater<int>());
    S[N-1] = X[N-1];
    for (int i = N-2; i >= 0; i--) {
        S[i] = X[i] + S[i+1];
    }
    for (int i = 1; i < N; i++) {
        if (X[i-1] == X[i]) nxt[i] = nxt[i-1]+1;
        else nxt[i] = 1;
    }
    cout << N << endl;
    int M = inf;
    for (int i = 1; i < N; i++) {
        ll tmp = S[i];
        ll dif = X[i-1], pos = 1;

        ll ans = 0;
        while (tmp) {
            if (tmp >= pos*dif) {
                tmp -= pos*dif;
                ans += dif;
            } else {
                ans += tmp/pos;
                break;
            }
            if (pos == i || nxt[i-pos] == 0) {
                ans += tmp/(i+1);
                break;
            }
            pos += nxt[i-pos];
            dif = X[i-pos]-X[i-pos+1];
        }
        cout << ans << endl;
    }
}