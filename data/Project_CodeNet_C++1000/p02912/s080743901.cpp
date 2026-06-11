#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    rep(i, n) {
        int a;
        cin >> a;
        s.insert(a);
    }
    rep(i, m) {
        int k = *s.rbegin();
        s.erase(s.find(k));
        k /= 2;
        s.insert(k);
    }
    ll sum = 0;
    for(auto x : s) {
        sum += (ll) x;
    }
    cout << sum << endl;
    return 0;
}
