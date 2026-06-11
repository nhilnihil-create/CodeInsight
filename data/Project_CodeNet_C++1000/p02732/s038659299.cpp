#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<Int> a(n);
    map<Int, Int> mp;
    map<Int, Int> sum;
    rep(i, n) {
         cin >> a[i];
         mp[a[i]]++;
    }
    Int sum_all = 0;
    for (auto m : mp) {
        sum[m.first] = (m.second * (m.second-1))/2;
        sum_all += (m.second * (m.second-1))/2;
    }
    rep(i, n) {
        Int before = sum[a[i]];
        Int after = (mp[a[i]]-1) * (mp[a[i]] -2) /2 ;
        cout << sum_all - (before - after) << endl;
    }

}