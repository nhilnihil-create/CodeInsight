#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define int long long

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    priority_queue<int> q;
    rep(i,n) {int a; cin >> a; q.push(a);}
    rep(i,m) {int a = q.top(); q.pop(); q.push(a/2);}
    int ans = 0;
    rep(i,n) {ans += q.top(); q.pop();}
    cout << ans << endl;
    return 0;
}