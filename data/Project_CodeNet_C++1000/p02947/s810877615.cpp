#include <bits/stdc++.h>
using namespace std;

long long nc2(long long a) {
    return a * (a - 1) / 2;
}

int main() {
    long long n;
    cin >> n;

    vector<string> arr(n);
    map<string, long long> mp;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        sort(arr[i].begin(), arr[i].end());
        mp[arr[i]]++;
    }

    long long ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans = ans + nc2(it->second);
    }

    cout << ans << endl;
}