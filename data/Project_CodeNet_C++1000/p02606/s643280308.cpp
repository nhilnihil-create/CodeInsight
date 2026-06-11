#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define INF 987654321

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, r, d, cnt = 0;
    cin >> l >> r >> d;
    for (int i = l; i <= r; i++) {
        if (i % d == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}