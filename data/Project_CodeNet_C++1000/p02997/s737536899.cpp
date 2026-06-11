#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<int, int> P;
ll modnum = 1e9+7;



int main() {
    int n,k; cin >> n >> k;
    // スターグラフが最短距離=2の数が最大になるグラフ
    // この数は1からN-1までの和
    // 1から最短経路2の頂点は2,3,4...N-1
    // 2から最短経路2の頂点は3,4...N-1
    // 3からは4,5..
    // N-2からはN-1
    int maximum = (n-1)*(n-2)/2;
    // スターグラフでKより少ない場合は作れないので-1を出力
    if(maximum < k) cout << -1 << endl;
    else {
        vector<P> res;
        // スターグラフの構築, Nに対して1..N-1を結び
        for(int i=1; i < n; i++) res.emplace_back(i, n);

        // 例えば1と2を結ぶ線を繋ぐと、もともとは1-N-2の最短経路=2が潰されるので
        // 最短経路=2の数を1つだけ減らせる
        int rem = maximum - k;
        int ci = 1, cj = 2;
        for(int i=0; i < rem; i++) {
            res.emplace_back(ci, cj);
            cj++;
            // とりあえず, 1に対して2,3,4,...N-1を結んでいく
            // 全て達したら、2に対して3,4...N-1
            // それも達したら3に対して4,5...N-1
            // という感じで埋めれる
            if(cj == n) {
                ci++;
                cj = ci + 1;
            }
        }
        cout << res.size() << endl;
        for(auto p : res) cout << p.first << " " << p.second << endl;
    }
    return 0;
}
