#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    rep(i,k) {
        cout << s << ' ';
    }
    rep(i,n-k) {
        if (s == 1000000000) cout << 1 << ' ';
        else cout << s+1 << ' ';
    }
    return 0;
}