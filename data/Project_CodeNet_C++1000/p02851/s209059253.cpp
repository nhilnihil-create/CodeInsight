#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = (v-1+k)%k;
    }
    map<int, int> cnt;
    cnt[0] = 1;
    int s = 0;
    long long ans = 0;
    vector<int> pref = {0};
    for (int i = 0; i < n; i++) {
        int v = a[i];
        s = (s+v)%k;
        pref.push_back(s);
        int j = i + 1 - k;
        if (j >= 0) {
            cnt[pref[j]]--;
        }
        ans += cnt[s];
        cnt[s]++;
    }
    cout << ans << endl;
}
