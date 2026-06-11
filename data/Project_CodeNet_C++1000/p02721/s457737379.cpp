#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 2e5 + 5;
int pref[N], suf[N];
vector<int> pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, c;
    cin >> n >> k >> c;
//    n = 1e5, k = 1e4, c = 2;
    string s;
    cin >> s;
    s = 'x' + s;
    pos.push_back(-1e9);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'o')pos.push_back(i);
        pref[i] = pref[i - 1];
        if (s[i] == 'o') {
            int indx = 0;
            auto it = lower_bound(pos.begin(), pos.end(), i - c);
            it--;
            indx = max(0, *it);
            pref[i] = max(pref[i], pref[indx] + 1);
        }
    }
    pos.push_back(1e9);
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == 'o') {
            int indx = 0;
            auto it = upper_bound(pos.begin(), pos.end(), i + c);
            indx = min(n + 1, *it);
            suf[i] = max(suf[i], suf[indx] + 1);
        }
    }
//    for (int i = 1; i <= n; i++)
//        cout << pref[i] << " " << suf[i] << endl;
//    return 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {n + 1, 0}});
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'x') continue;
        while (pq.top().second.first <= i) {
            int x = pq.top().second.first;
            auto it = upper_bound(pos.begin(), pos.end(), x);
            int indx = pq.top().second.second;
            pq.pop();
            pq.push({pref[indx] + suf[min(n + 1, *it)], {*it, indx}});
        }
        int tmp = pq.top().first;
        tmp = max(tmp, suf[i + 1]);
        tmp = max(tmp, pref[i - 1]);
        if (tmp < k) cout << i << '\n';
        int indx = 0;
        auto it = upper_bound(pos.begin(), pos.end(), i + c);
        indx = min(n + 1, *it);
        pq.push({pref[i] + suf[indx], {indx, i}});
    }

    return 0;
}