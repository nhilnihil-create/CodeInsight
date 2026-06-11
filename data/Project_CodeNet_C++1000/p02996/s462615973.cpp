#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> ba(n);
    rep(i, n) cin >> ba[i].second >> ba[i].first;
    sort(ba.begin(), ba.end());
    string ans = "Yes";
    ll sum = 0;
    rep(i, n) {
        sum += ba[i].second;
        if(sum > ba[i].first) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
