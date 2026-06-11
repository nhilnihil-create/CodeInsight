#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string s;
    cin >> k >> s;
    if (s.size() > k) {
        s = s.substr(0,k).append(3,'.');
    }
    cout << s;
}
