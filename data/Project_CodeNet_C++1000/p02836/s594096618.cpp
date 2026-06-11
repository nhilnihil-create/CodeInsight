#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i * 2 < n - 1; i++) {
        if (s[i] != s[n - i - 1]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}