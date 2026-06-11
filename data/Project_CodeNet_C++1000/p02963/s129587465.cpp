#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll s;
    cin >> s;
    const int v = 1000000000;
    int y3 = (s+v-1)/v;
    int x3 = v*y3 - s;
    cout << "0 0 1000000000 1 " << x3 << " " << y3 << endl;
}