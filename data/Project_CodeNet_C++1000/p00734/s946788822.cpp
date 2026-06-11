#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    while (cin >> n >> m, n) {
        int t[110], h[110], sumt = 0, sumh = 0;
        for (int i = 0; i < n; i++) {
            cin >> t[i];
            sumt += t[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> h[i];
            sumh += h[i];
        }
        
        int flag = 0, cpyt, cpyh;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cpyt = sumt - t[i] + h[j];
                cpyh = sumh - h[j] + t[i];
                if (cpyt != cpyh) continue;
                cout << t[i] << " " << h[j] << endl;
                flag = 1;
                break;
            }
            if (flag) break;
        }

        if (!flag) cout << "-1\n";
    }

    return 0;
}