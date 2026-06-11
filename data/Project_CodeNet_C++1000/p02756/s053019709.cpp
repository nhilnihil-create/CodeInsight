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
    string s;
    cin >> s;
    deque<char> d(s.begin(), s.end());
    bool reversed = false;
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            reversed ^= 1;
        } else {
            int f; char c;
            cin >> f >> c;
            if((f == 1) ^ reversed) {
                d.push_front(c);
            } else {
                d.push_back(c);
            }
        }
    }
    string ans(d.begin(), d.end());
    if(reversed) {
        reverse(ans.begin(), ans.end());
    }
    cout << ans << endl;
    return 0;
}
