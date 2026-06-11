#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    int a[n]; rep(i, n) cin >> a[i];
    int b[n], c[n];
    map<int, int> cnt_b;
    rep(i, n){
        b[i] = i+1 + a[i];
        c[i] = i+1 - a[i];
    }
    lint ans = 0;
    for (int j = 1; j < n; j++){
        ans += cnt_b[c[j]];
        if (c[j] == b[j-1]) ans++;
        cnt_b[b[j-1]] ++;
    }
    cout << ans << endl;
}