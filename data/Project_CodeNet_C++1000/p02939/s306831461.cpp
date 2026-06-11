#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string x;
    cin >> x;
    int ans = 1;
    int take = 1;
    for (int i = 1; i < x.size(); i++) {
        if (take == 1) {
            if (x[i] == x[i - 1]) {
                if (i == x.size() - 1) break;
                take = 2;
                i++;
            }
            else {
                take = 1;
            }
        }
        else {
            take = 1;
        }
        ans++;
    }
    cout << ans;
    return 0;
}