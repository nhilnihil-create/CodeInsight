#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

const ll INF = 1LL << 50;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (auto& p : P) {
        cin >> p;
        --p;
    }
    vector<ll> C(N);
    for (auto& c : C) {
        cin >> c;
    }
    ll ans = -INF;
    rep(u, 0, N) {
        int nxt_node = P[u];
        int loop_length = 1;
        ll loop_cost = C[nxt_node];
        while (nxt_node != u) {
            nxt_node = P[nxt_node];
            loop_cost += C[nxt_node];
            ++loop_length;
        }
        if (loop_cost > 0) {
            // 回れるだけ回る
            ll loop_cnt = K / loop_length;
            ll now_ans = loop_cost * loop_cnt;
            if (loop_cnt) {
                chmax(ans, now_ans);
            }
            int rest = K % loop_length;
            int now_node = P[u];
            rep(i, 0, rest) {
                now_ans += C[now_node];
                chmax(ans, now_ans);
                now_node = P[now_node];
            }
            // 1周分だけ少なく回る
            now_ans = loop_cost * max(0LL, loop_cnt - 1);
            now_node = P[u];
            rep(i, 0, K - max(0LL, loop_cnt - 1) * loop_length) {
                now_ans += C[now_node];
                chmax(ans, now_ans);
                now_node = P[now_node];
            }
        }
        // 1周より多く回らない
        nxt_node = P[u];
        ll now_ans = C[nxt_node];
        chmax(ans, now_ans);
        int rest = K - 1;
        while (nxt_node != u && rest) {
            nxt_node = P[nxt_node];
            now_ans += C[nxt_node];
            --rest;
            chmax(ans, now_ans);
        }
    }
    cout << ans << endl;
    return 0;
}