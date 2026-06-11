#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    ll n = s.size();
    vector<ll> ans(n+1, 0);

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i+1] == 'L') {
            int j = i, rc = 0, lc = 0;
            while (j-1 >= 0 && s[j-1] == 'R') {
                rc++;
                j--;
            }
            j = i+1;
            while (j+1 < n && s[j+1] == 'L') {
                lc++;
                j++;
            }
            int rans;
            int lans = rans = (rc + lc + 2) / 2;
            if (rc > lc && (rc + lc) % 2 != 0) rans++;
            else if (lc > rc && (rc + lc) % 2 != 0) lans++;

            if (max(lc, rc) % 2 == 0) {
                ans[i] = rans;
                ans[i+1] = lans;
            } else {
                ans[i] = lans;
                ans[i+1] = rans;
            }
            i++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}