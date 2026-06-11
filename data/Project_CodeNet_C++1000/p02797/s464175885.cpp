//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    if(s != 1000000000) {
        rep(i, k) {
            cout << s << (i == n-1?'\n':' ');
        }
        rep(i, n-k) {
            cout << s+1 << (i == n-1-k?'\n':' ');
        }
    } else {
        rep(i, k) {
            cout << s << (i == n-1?'\n':' ');
        }
        rep(i, n-k) {
            cout << 1 << (i == n-1-k?'\n':' ');
        }
    }
}