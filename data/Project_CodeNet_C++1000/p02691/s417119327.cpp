#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> a(n);
    rep(i, n) cin >> a[i];
    vector<lli> l(n), r(n);
    rep(i, n){
        l[i] = i+a[i];
        r[i] = i-a[i];
    }
    unordered_map<lli, lli> mpl, mpr;
    unordered_map<lli, bool> mpg;
    rep(i, n) mpl[l[i]]++, mpg[l[i]] = true;
    rep(i, n) mpr[r[i]]++, mpg[r[i]] = true;
    lli ans = 0;
    for(auto i : mpg){
        ans += mpl[i.first]*mpr[i.first];
    }
    cout << ans << endl;
    return 0;
}
