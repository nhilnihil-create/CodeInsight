#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> snuke(n,false);
    int d, a;
    for (int i = 0; i < k; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> a;
            snuke[a-1] = true;
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (snuke[i] == false) {
            s++;
        }
    }
    cout << s;
}
