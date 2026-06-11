#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int H, W, M; cin >> H >> W >> M;
    //vector<int> h(M), w(M);
    //rep(i,M) cin >> h[i] >> w[i];
    vector<int> hs(H), ws(W);
    set<pair<int,int>> s;
    rep(i,M){
        int h, w;
        cin >> h >> w;
        --h; --w;
        hs[h]++;
        ws[w]++;
        s.emplace(h,w);
    }

    // 縦と横の最大出現回数を取得
    int mh = 0;
    int mw = 0;
    rep(i,H) mh = max(mh, hs[i]);
    rep(i,W) mw = max(mw, ws[i]);

    // 最大の出現回数のインデックスを取得
    vector<int> h_indices, w_indices;
    rep(i,H) if (mh == hs[i]) h_indices.push_back(i);
    rep(i,W) if (mw == ws[i]) w_indices.push_back(i);
    // 暫定で最大値を答えに設定 
    int ans = mh+mw;
    for(auto h_index : h_indices){
        for (auto w_index : w_indices){
            if (s.count(make_pair(h_index, w_index))>0) continue;
            // 重複がなかった場合は暫定を最大値として出力
            cout << ans << endl;
            return 0;
        }
    }
    // 重複がない箇所がなかった場合は、最大値-1を出力
    cout << --ans << endl;
    
}