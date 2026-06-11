#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
        if(mp.count(i + a.at(i))) mp[i + a.at(i)]++;
        else mp[i + a.at(i)] = 1;
    }

    for (int i = 1; i <= n; i++) {
        int x = i - a.at(i);
        if(x <= 0) continue;
        else ans += mp[x];
    }
    cout << ans << endl;
}