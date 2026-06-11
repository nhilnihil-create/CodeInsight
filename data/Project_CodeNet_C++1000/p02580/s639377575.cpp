#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int H, W, M; cin >> H >> W >> M;
    vector<int> cntH(H), cntW(W), bombH(M), bombW(M);
    int max_h = -1, max_w = -1;
    rep(i, M){
        int a, b; cin >> a >> b; a--; b--;
        cntH[a]++, cntW[b]++;
        chmax(max_h, cntH[a]); chmax(max_w, cntW[b]);
        bombH[i] = a, bombW[i] = b;
    }
    int res = max_h + max_w;
    ll maxh_cnt = 0, maxw_cnt = 0, closs_cnt = 0;

    rep(i, H){
        if(cntH[i]==max_h)maxh_cnt++;
    }
    rep(i, W){
        if(cntW[i]==max_w)maxw_cnt++;
    }

    rep(i, M){
        int a = bombH[i], b = bombW[i];
        if(cntH[a] == max_h && cntW[b] == max_w)closs_cnt++;
    }
    if(closs_cnt == maxh_cnt * maxw_cnt)res--;
    cout << res << ln;
}
    
