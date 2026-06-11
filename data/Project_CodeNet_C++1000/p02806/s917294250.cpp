#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i].first >> l[i].second;
    string x;
    cin >> x;
    
    int y;
    for (int i = 0; i < n; i++) {
        if (l[i].first == x) {
            y = i;
            break;
        }
    }

    int ans = 0;
    for (int i = y+1; i < n; i++) {
        ans += l[i].second;
    }

    cout << ans << endl;    
}