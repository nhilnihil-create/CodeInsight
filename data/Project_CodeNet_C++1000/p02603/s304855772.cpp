//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int main () {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    /*int mx = *max_element(all(a));
    if (a[0] == mx) {
        cout << 1000 << endl;
        return 0;
    }*/
    vector<int> buy, sell;
    if (a[0] <= a[1]) buy.push_back(0);
    rep(i, n-2) {
        if (a[i] > a[i+1] && a[i+1] <= a[i+2]) buy.push_back(i+1);
        if (a[i] <= a[i+1] && a[i+1] > a[i+2]) sell.push_back(i+1);
    }
    if (a[n-2] <= a[n-1]) sell.push_back(n-1);
    int l = min(buy.size(), sell.size());
    /*
    cout << "buy:";
    rep(i, buy.size()) printf("%d ", buy[i] + 1);
    cout << endl <<  "sell:";
    rep(i, sell.size()) printf("%d ", sell[i] + 1);
    cout << endl;
    */

    ll m = 1000;
    ll stock = 0;
    rep(i, l) {
        stock = m / a[buy[i]];
        m -= stock * a[buy[i]];
        //cout << m << endl;
        m += stock * a[sell[i]];
        stock = 0;
        //cout << m << endl;
    }
    cout << m << endl;

    return 0;
}