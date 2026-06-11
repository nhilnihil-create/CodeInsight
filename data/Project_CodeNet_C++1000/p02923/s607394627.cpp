#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    int ma = 0;
    int cnt = 0;
    int prev = a.at(0);
    for (int i = 1; i < n; i++) {
        if (prev >= a.at(i)) {
            cnt++;
        }
        else {
            ma = max(ma, cnt);
            cnt = 0;
        }
        prev = a.at(i);
    }
    cout << max(ma, cnt) << endl;
    return 0;
}