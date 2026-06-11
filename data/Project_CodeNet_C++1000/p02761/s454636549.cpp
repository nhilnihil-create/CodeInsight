#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, -1);
    for (int i = 0; i < m; i++) {
        int s, c;
        cin >> s >> c;
        s--;
        if (a[s] >= 0 && a[s] != c) {
            puts("-1");
            return 0;
        }
        a[s] = c;
    }
    if (a[0] == 0 && n > 1) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (i == 0 && n > 1) a[i] = 1;
            else a[i] = 0;
        }
        cout << a[i];
    }
    cout << "\n";
}
