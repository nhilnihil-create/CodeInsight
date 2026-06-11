#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, k;

int main() {
    cin >> n >> k;
    int limit = (n-1)*(n-2)/2;
    if(k > limit) cout << -1 << endl;
    else {
        int cnt = limit-k;
        cout << cnt+(n-1) << endl;
        bool flg = true;
        for(int i = 2; i <= n; ++i) {
            cout << 1 << " " << i << endl;
        }
        for(int u = 2; u <= n; ++u) {
            for(int v = u+1; v <= n; ++v) {
                if(cnt != 0) {
                    cout << u << " " << v << endl;
                }else {
                    flg = false;
                    break;
                }
                cnt--;
            }
            if(!flg) break;
        }
    }
}