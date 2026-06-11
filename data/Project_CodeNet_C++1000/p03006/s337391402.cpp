#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int p=x[j]-x[i], q=y[j]-y[i];
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (k!=l) {
                            if (x[k]+p==x[l] && y[k]+q==y[l]) cnt++;
                        }
                    }
                }
                ans = min(ans, n-cnt);
            }
        }
    }
    cout << ans << endl;
}
