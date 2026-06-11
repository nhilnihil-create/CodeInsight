#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (strncmp(&s[i], "ABC", 3) == 0)
            cnt++;
    }
    cout << cnt << endl;
}