#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> pos, neg;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if (A >= 0) pos.push_back(A);
        else neg.push_back(A);
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.rbegin(), neg.rend());
    if (neg.size() == 0) {
        neg.push_back(pos.back());
        pos.pop_back();
    }
    int x = neg[0];
    vector<pair<int, int>> ans;
    if (pos.size() > 0) {
        for (int i = 0; i < pos.size() - 1; i++) {
            ans.push_back({x, pos[i]});
            x -= pos[i];
        }
        ans.push_back({pos.back(), x});
        x = pos.back() - x;
    }
    for (int i = 1; i < neg.size(); i++) {
        ans.push_back({x, neg[i]});
        x -= neg[i];
    }
    cout << x << '\n';
    for (auto& p : ans) cout << p.first << " " << p.second << '\n';
}