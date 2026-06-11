/*
    Problem 97
    https://atcoder.jp/contests/abc150/tasks/abc150_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
ll cntDiv2(ll a) {
    ll b = a;
    ll ret = 0;
    for (; b%2== 0; b/=2, ret++) {}
    return ret;
}
ll gcd(ll x, ll y) {return (y ? gcd(y, x%y) : x);}
/* main */
int main(){
    int N, M;
    cin >> N >> M;
    set<ll> A;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        A.insert(a/2);
    }
    set<ll> B;
    for (ll a : A) { B.insert(cntDiv2(a)); }
    if (B.size() > 1) {
        cout << 0 << '\n';
        return 0;
    }
    ll lcm = 1;
    for (ll a : A) {lcm = lcm / gcd(lcm, a) * a;}
    ll ans = (M / lcm + 1) / 2;
    cout << ans << '\n';
}