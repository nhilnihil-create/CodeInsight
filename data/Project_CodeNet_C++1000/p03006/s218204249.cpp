#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    

    int ans = 50;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int p = x[i] - x[j];
            int q = y[i] - y[j];
            bool check[n];
            for (int k = 0; k < n; k++) check[k] = false;
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (check[k]) continue;
                cnt++;
                check[k] = true;
                queue<int> que;
                que.push(k);
                while (que.size() > 0) {
                    int h = que.front();
                    que.pop();
                    for (int nh = 0; nh < n; nh++) {
                        if (check[nh]) continue;
                        if (x[nh] - x[h] == p && y[nh] - y[h] == q || x[h] - x[nh] == p && y[h] - y[nh] == q) {
                            check[nh] = true;
                            que.push(nh);
                        }
                    }
                }
            }
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}