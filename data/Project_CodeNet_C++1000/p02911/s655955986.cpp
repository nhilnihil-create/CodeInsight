#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n,k,q; cin >> n >> k >> q;
    int sankas[100000];
    rep(i,n) sankas[i] = k;
    rep(i,q) {
        int a; cin >> a;
        sankas[a-1] ++;
    }
    rep(i,n) {
        if (sankas[i] - q > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}