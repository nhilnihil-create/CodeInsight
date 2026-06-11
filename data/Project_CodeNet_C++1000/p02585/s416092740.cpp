#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;
 
void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}
 
struct point {
    ll next;
    ll score;
};
 
ll get_cluster_result(vector<point>& points, vector<bool>& done, ll start, ll K) {
    ll loop_score = 0;
    vector<ll> cluster;
    for (point p = points[start]; true; p = points[p.next]) {
        cluster.push_back(p.next);
        done[p.next] = true;
        loop_score += points[p.next].score;
        if (p.next == start) {
            break;
        }
    }
 
    ll size = cluster.size();
    ll shu = 0;
    ll rest_move;
    if (loop_score > 0) {
        shu = max(0LL, K / size - 1LL);
        rest_move = K - shu * size;
    } else {
        rest_move = min(K, size);
    }

    ll max_rest = -INF;
    for (ll c : cluster) {
        ll rest_score = 0;
        point p = points[c];
        for (ll j = 0; j < rest_move; j++) {
            rest_score += points[p.next].score;
            p = points[p.next];
            max_rest = max(max_rest, rest_score);
        }
    }
    return max_rest + shu * loop_score;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<point> points(N + 1, {-1,0});
    for (ll i = 1; i <= N; i++) {
        cin >> points[i].next;
    }
    for (ll i = 1; i <= N; i++) {
        cin >> points[i].score;
    }
    vector<bool> done(N + 1, false);
 
    ll gresult = -INF;
    for (ll i = 1; i <= N; i++) {
        if (!done[i]) {
            gresult = max(gresult, get_cluster_result(points, done, i, K));
        }
    }
    print(gresult);
}
