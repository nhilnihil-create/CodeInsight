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
    int n;
    cin >> n;
    vector<P> hani(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        hani[i] = P(a+b, a-b);
    }

    sort(all(hani));
    int ans = 0;
    int now = INT_MIN;
    rep(i, n) {
        if(now <= hani[i].second) {
            ans++;
            now = hani[i].first;
        }
    }

    cout << ans << endl;
}