#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for (int i = 0, len = n - 2; i < len; i++) {
        if (s.at(i) == 'A' && s.at(i + 1) == 'B' && s.at(i + 2) == 'C') {
            cnt++;
        }
    }
    cout << cnt << endl;
}
