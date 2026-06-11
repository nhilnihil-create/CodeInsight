#include <bits/stdc++.h>
using namespace std;

int cnt[2020];

int main() {
    string s;
    cin >> s;
    int now = 0;
    reverse(s.begin(), s.end());
    int base = 1;
    long long ans = 0;
    cnt[0]++;
    for (auto &c : s) {
        now = (now + (c - '0') * base) % 2019;
        ans += cnt[now]++;
        base = base * 10 % 2019;
    }
    cout << ans << endl;
    return 0;
}