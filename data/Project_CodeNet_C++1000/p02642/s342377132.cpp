#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;
using ll = long long;

const int MX = 1000001;

int main() {
    int n; cin >> n;
    int mn =0;
    vector<int> a(n); rep(i,n) {
        cin >> a[i];
        mn = max(mn, a[i]);
    }

    vector<int> tmp(MX,0);
    rep(i,n) {
        int b = a[i];
        if(tmp[b] > 1) continue;
        for(int j = b; j < mn+1; j+=b) {
            tmp[j]++;
        }
    }
    int ans = 0;
    rep(i,n) {
        if(tmp[a[i]] == 1) ans++;
    }
    cout << ans << endl;
}