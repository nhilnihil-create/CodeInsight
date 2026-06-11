#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (to_string(i).size() % 2) ans++;
    }
    cout << ans << "\n";
}