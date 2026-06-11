#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N, D, A; cin >> N >> D >> A;
    vector<P> monster(N);
    rep(i, N){
        int x, h; cin >> x >> h;
        monster[i] = {x, h};
    }
    sort(monster.begin(), monster.end());
    vector<ll> attack_cnt(N+1);
    vector<ll> required_cnt(N);
    rep(i, N){
        required_cnt[i] = ceil((double)monster[i].second / A);
    }
    ll ans = 0;
    int idx = 0;
    rep(i, N){
        while(monster[idx].first <= monster[i].first + 2 * D && idx < N) idx++;
        int nowattack = max((ll)0, required_cnt[i] - attack_cnt[i]);
        ans += nowattack;
        attack_cnt[i] += nowattack;
        attack_cnt[idx] -= nowattack;
        attack_cnt[i+1] += attack_cnt[i];
    }
    cout << ans << endl;
    return 0;
}
