//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    ll s;
    cin >> s;

    ll x1, y1, x2, y2;
    x1 = 1000000000LL;
    y1 = 1LL;
    y2 = (s+x1-1)/x1;
    x2 = (x1-s%x1)%x1;
    cout << "0 0" << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}