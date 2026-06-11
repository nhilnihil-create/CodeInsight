#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
using namespace std;
const int N = 2e5+5;
int n;
ii t[N];
main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        t[i] = {b, a};
    }
    sort(t, t+n);
    int cur = 0, ans = 1;
    for(int i=0; i<n; i++) {
        int a = t[i].second,
            b = t[i].first;
        cur += a;
        if(cur > b) {
            ans = 0;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << "\n";
}
