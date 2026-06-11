#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

vector<int> jumps;
vector<int> scores;
ll N, K;

tuple<ll, ll, ll> solve(int from, int max_cnt) {
    if (max_cnt == 0) return make_tuple(0, -1, 0);

    int pos = from;
    int cnt = 0;
    ll sum = 0;
    ll max_score = -1e16;
    for(;;) {
        // jump to next
        pos = jumps[pos];
        sum += scores[pos];
        ++cnt;

        max_score = max(max_score, sum);
        if (pos == from) break;
        if (cnt >= max_cnt) return make_tuple(max_score, -1, max_cnt);
    } 
    return make_tuple(max_score, sum, cnt);
}


int main()
{
    // read input
    cin >> N >> K;
    jumps.assign(N, 0);
    scores.assign(N, 0);
    rep(i, 0, N) cin >> jumps[i];
    rep(i, 0, N) --jumps[i];
    rep(i, 0, N) cin >> scores[i];

    ll ans = scores[0];
    rep(from, 0, N) {
        ll max_score, offset, cnt;
        tie(max_score, offset, cnt) = solve(from, K);

        // printf("from: %d, max_score: %lld, offset: %lld, cnt: %lld\n", from, max_score, offset, cnt);

        if (offset <= 0) {
            ans = max(ans, max_score);
            continue;
        }
        else 
        {
            ans = max(ans, offset*(K/cnt-1) + max_score);

            max_score = get<0>(solve(from, K%cnt));
            ans = max(ans, offset*(K/cnt) + max_score);
        }
    }

    cout << ans << endl;
    return 0;
}

