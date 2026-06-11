#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    map<string , int> cnt;

    long long ans = 0;
    for (int i = 1 ;i <= n ;i++) {
        string num = to_string(i);
        ans += cnt[string(1 , num.back()) + num.front()];
        cnt[string(1 , num.front()) + num.back()]++;
        ans += cnt[string(1 , num.back()) + num.front()];
    }

    cout << ans;
}