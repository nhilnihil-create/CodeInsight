#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> nus(n, false);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            nus.at(a - 1) = true;
        }
    }
    int cnt = 0;
    for (auto a : nus) {
        if(!a)
            cnt++;
    }
    cout << cnt << endl;
}
