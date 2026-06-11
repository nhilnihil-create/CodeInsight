// 卍 嘘解上等 卍
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
 
int main() {
    lint n; cin >> n;
    vector<lint> a(n);
    rep(i,n) cin >> a[i];
    bool ans = false;
    sort(a.begin(),a.end(), greater<lint>());
    multiset<lint> setA;
    for(int i=1; i<n; i++) setA.insert(a[i]);
    vector<lint> r(n+1);
    r[0] = a[0];
    r[n] = a[0];
    for(int i=1; i<n; i++) {
        setA.erase(setA.find(a[i]));
        lint want = r[0] ^ a[i];
        auto it = setA.find(want);
        if (it != setA.end()) {
            setA.erase(it);
            r[1] = want;
            r[2] = a[i];
            ans = true;
            break;
        }
        setA.insert(a[i]);
    }
    if (ans) {
        for(int i=3; i<n; i++) {
            lint want = r[i-2] ^ r[i-1];
            auto it = setA.find(want);
            if (it != setA.end()) {
                setA.erase(it);
                r[i] = want;
            } else {
                ans = false;
                break;
            }
        }
    }
    auto o = ans ? "Yes" : "No";
    cout << o << endl;
}