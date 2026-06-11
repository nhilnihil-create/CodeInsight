#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef float fl;
typedef long long ll;

vector<pair<int, int> > h;

// 1文字固定することを考える。固定したら片方の依存関係を除去する。
// i < j
// j - i = a[i] + a[j]
// a[i] + i = j - a[j] 

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    ll ans = 0;
    rep(i,n) {
        int sa = i - a[i];
        ans += mp[sa];
        // 予め記録しておく
        int wa = a[i] + i;
        mp[wa]++;
    }
    cout << ans << endl;
    return 0;
}