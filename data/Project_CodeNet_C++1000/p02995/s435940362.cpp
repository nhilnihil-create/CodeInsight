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
ll A, B, C, D;
/* function */
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x;}
ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}
ll f (ll x) {
    ll ret = B / x - (A-1) / x;
    return ret;
}
/* main */
int main(){
    cin >> A >> B >> C >> D;
    ll divCorD = f(C) + f(D) - f(lcm(C, D));
    cout << (B - A + 1) - divCorD << '\n';
}
