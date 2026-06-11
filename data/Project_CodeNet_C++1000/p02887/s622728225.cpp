#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s.at(i) != s.at(i + 1)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}