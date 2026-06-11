#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, m, mr = INT_MAX, mm = INT_MAX;
    cin >> a >> b >> m;
    vector<int>r(a, 0), mic(b, 0);
    for(int i = 0; i < a; i++) {
        cin >> r[i];
        mr = min(mr, r[i]);
    }
    for(int i = 0; i < b; i++) {
        cin >> mic[i];
        mm = min(mm, mic[i]);
    }
    int x, y, c, ans = mr+mm;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        x--;
        y--;
        ans = min(ans, r[x] + mic[y] - c);
    }
    cout << ans << endl;
    return 0;
}
