#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    cin >> p >> q >> r;
    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    while(p.size() > x) p.pop_back();
    while(q.size() > y) q.pop_back();
    r.insert(r.end(), p.begin(), p.end());
    r.insert(r.end(), q.begin(), q.end());
    sort(r.begin(), r.end(), greater<int>());
    cout << accumulate(r.begin(), r.begin() + x + y, 0ll) << endl;
    return 0;
}
