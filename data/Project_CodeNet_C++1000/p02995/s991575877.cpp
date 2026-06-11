// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

ll get_undividable_num(ll p, ll q, ll X) {
    ll ans = X;
    ans -= X / p;
    ans -= X / q;
    ans += X / lcm(p, q);
    return ans;
}

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << get_undividable_num(C, D, B) - get_undividable_num(C, D, A - 1) << endl;

}