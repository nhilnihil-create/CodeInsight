#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);


const int INF = 1<<30;


int main() {
    int n,m; cin >> n >> m;
    string s; cin >> s;

    // 後ろからのDPテーブルを作成する
    // dp[i] : Nからiに到達するのに必要な最短手数
    // queueを使って計算量を減らしてる
    // queueのサイズ上限としてmにしておく
    // queueにはdp[i]の値がNから順番に入ってる。
    // これやれば、あるi地点を見るときに、queueの先頭にはNからi+mへの最短手数が入ってる。
    // 一回の移動で最大m移動できるので、Nからiへの最短手数は Nからi+mへの最短手数に+1した数となる
    vector<int> dp(n+1, INF);
    dp[n] = 0;
    queue<int> q;
    q.push(0);
    for(int i = n-1; i >= 0; i--) {
        while (true) {
            if(q.size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (q.front() != INF && q.size() <= m) break;
            q.pop();
        }
        if(s[i] == '0') dp[i] = q.front() + 1;
        q.push(dp[i]);
    }

    // dpテーブルを使って辞書順最短経路を見ていく
    vector<int> ans;
    // 現在いるマス
    int now = 0;
    // 残りのサイコロ振れる回数
    int rest = dp[0];
    while(now < n) {
        --rest;
        int move = 1;
        // 最初に最短経路数が変わる場所が辞書順最短手順
        while(dp[now+move] != rest) move++;
        ans.push_back(move);
        now += move;
    }
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}

