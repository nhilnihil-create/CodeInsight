#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    s[n] = 'R';
    char dir = 'R';
    int cnt = 1;
    vector<int> child(n, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') {
            if (dir == 'R') {
                cnt++;
            } else {
                child[i - cnt] += cnt / 2 + cnt % 2;
                child[i - cnt - 1] += cnt / 2;
                dir = 'R';
                cnt = 1;
            }
        } else {
            if (dir == 'L') {
                cnt++;
            } else {
                child[i - 1] += cnt / 2 + cnt % 2;
                child[i] += cnt / 2;
                dir = 'L';
                cnt = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << child[i];
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}