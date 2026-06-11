#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, num = 1, cnt = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x == num) num++;
        else cnt++;
    }
    if (num == 1 && cnt != 0) cout << -1 << endl;
    else cout << cnt << endl;
}