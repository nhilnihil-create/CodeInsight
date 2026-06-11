#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int h, w, a, b;

int main() {
    cin >> h >> w >> a >> b;
    vector<vector<int>> smap(h, vector<int>(w, 1));
    for(int i = 0; i < b; ++i) {
        for(int j = 0; j < a; ++j) smap[i][j] = 0;
    }
    for(int i = b; i < h; ++i) {
        for(int j = a; j < w; ++j) smap[i][j] = 0;
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cout << smap[i][j];
        }
        cout << endl;
    }
}