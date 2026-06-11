//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N, D, A; cin >> N >> D >> A;
    vector<pair<int, int>> monster(N);
    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        int X, H; cin >> X >> H;
        pos[i] = X;
        monster[i] = make_pair(X, H);
    }

    sort(pos.begin(), pos.end());
    sort(monster.begin(), monster.end());

    vector<int> attack(N);

    long long ans = 0;

    attack[0] = (monster[0].second + A - 1) / A;
    auto it = upper_bound(pos.begin(), pos.end(), pos[0] + 2 * D);
    if (it != pos.end()) attack[it - pos.begin()] -= (monster[0].second + A - 1) / A;

    ans += (monster[0].second + A - 1) / A;


    for (int i = 1; i < N; i++) {

        attack[i] += attack[i-1];
        monster[i].second -= attack[i] * A;

        if (monster[i].second <= 0) continue;

        attack[i] += (monster[i].second + A - 1) / A;
        auto itr = upper_bound(pos.begin(), pos.end(), pos[i] + 2 * D);
        if (itr != pos.end()) attack[itr - pos.begin()] -= (monster[i].second + A - 1) / A;

        ans += (monster[i].second + A - 1) / A;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}