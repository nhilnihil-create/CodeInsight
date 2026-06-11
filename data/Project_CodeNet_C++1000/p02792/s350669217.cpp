#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int count[10][10] = {0};
    for(int i=1; i<=n; i++) {
        string s = to_string(i);
        count[s[0] - '0'][s[s.size()-1] - '0']++;
    }
    ll ans = 0;
    for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
            ans += count[i][j] * count[j][i];
        }
    }
    cout << ans << "\n";
}