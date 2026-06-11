#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int64_t N, D, A;
    cin >> N >> D >> A;
    vector< pair<int64_t,int64_t> > monster(N);
    for(int i=0; i<N; i++) {
        cin >> monster[i].first >> monster[i].second;
    }

    sort(monster.begin(), monster.end());

    int64_t ans = 0;
    int64_t damage = 0;
    queue< pair<int64_t,int64_t> > q;
    for(int i=0; i<N; i++) {
        while(!q.empty() && q.front().first < monster[i].first) {
            damage -= q.front().second;
            q.pop();
        }
        monster[i].second -= damage;
        if(monster[i].second <= 0) continue;
        int64_t cnt = (monster[i].second + A-1) / A;
        ans += cnt;
        damage += cnt*A;
        q.emplace(monster[i].first + 2*D, cnt*A);
    }

    cout << ans << endl;
    return 0;
}
