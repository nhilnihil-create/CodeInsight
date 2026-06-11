#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(string x, int target, int k) {
    vector<int> vec;
    for (auto q : x) {
        if (q == 'L') vec.push_back(1);
        else vec.push_back(0);
    }
    priority_queue<pair<int, int>> pq, pq2;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == (target ^ 1)) {
            int cnt = 0;
            int tmp = i;
            for (int j = i; j < vec.size(); j++, i++) {
                if (vec[j] == (target ^ 1)) cnt++;
                else break;
            }
            if (tmp == 0 || i == vec.size() - 1)pq2.push({cnt, tmp});
                else pq.push({cnt, tmp});
            i--;
        }
    }
    int cnt = 0;
    while (pq.size()) {
        for (int i = pq.top().second; i < vec.size(); i++)
            if (vec[i] == (target ^ 1)) vec[i] = target;
            else break;
        pq.pop();
        if (++cnt == k) break;
    }
    while (pq2.size()) {
        if (cnt == k) break;
        for (int i = pq2.top().second; i < vec.size(); i++)
            if (vec[i] == (target ^ 1)) vec[i] = target;
            else break;
        pq2.pop();
        if (++cnt == k) break;
    }
    int ans = 0;
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] == vec[i + 1]) ans++;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1]) ans++;
    cout << max(ans, max(solve(s, 1, k), solve(s, 0, k)));
    return 0;
}
