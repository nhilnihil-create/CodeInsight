#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n =(int)s.size();
    vector<int> l(n), r(n);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'R') {
            r[i] = (i < n - 1 ? r[i + 1] : 0)+ 1;
        } else {
            r[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            l[i] = (i ? l[i - 1] : 0) + 1;
        } else {
            l[i] = 0;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int cnt;
        if (s[i] == 'L') {
            cnt = l[i];
            if (cnt % 2 == 0) {
                ans[i - cnt]++;
            } else{
                ans[i - cnt + 1]++;
            }
        } else {
            cnt = r[i];
            if (cnt % 2 == 0) {
                ans[i + cnt]++;
            } else {
                ans[i + cnt - 1]++;
            }
        }
    }
    for (int i = 0; i < n; i++){
       cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}

