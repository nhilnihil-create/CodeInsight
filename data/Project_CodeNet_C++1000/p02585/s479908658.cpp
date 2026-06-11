#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    constexpr ll NINF = -(1LL<<60);
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    REP(i,N) {cin >> P[i]; P[i]--;}
    vector<ll> C(N);
    REP(i,N) cin >> C[i];
    // ループのグループ
    vector<int> loopg(N);
    int cntloopg = 1;
    // ループサイズ
    vector<int> loopsize(1);
    // ループグループごとの歩数別最大スコア
    vector<vector<ll>> loopmaxscore(1,vector<ll>(1));
    // ループグループごとの1周スコア
    vector<ll> loopscore(1);


    ll ans = NINF;
    REP(i,N) {
        if (loopg[i] == 0) {
            int pos = P[i];
            int loops = 0;
            ll score = 0;
            while(loopg[i] == 0) {
                score += C[pos];
                loopg[pos] = cntloopg;
                pos = P[pos];
                loops++;
            }
            loopsize.push_back(loops);
            loopscore.push_back(score);
            loopmaxscore.push_back(vector<ll>(loops+1,NINF));
            cntloopg++;
            // cerr << i+1 << " " << score << " " << loops << endl;
        }

        int pos = P[i];
        ll score = 0;
        REP(j,loopsize[loopg[i]]) {
            score += C[pos];
            pos = P[pos];
            loopmaxscore[loopg[i]][j] = max(loopmaxscore[loopg[i]][j],score);
            if (j != 0) loopmaxscore[loopg[i]][j] = max(loopmaxscore[loopg[i]][j],loopmaxscore[loopg[i]][j-1]);
        }
        int loopnum = K / loopsize[loopg[i]];
        int loopmod = K % loopsize[loopg[i]];
        ll tmp = 0;
        if (loopnum == 0) tmp = loopmaxscore[loopg[i]][loopmod-1];
        else {
            if (loopscore[loopg[i]] < 0) tmp = loopmaxscore[loopg[i]][loopsize[loopg[i]]-1];
            else {
                tmp = loopscore[loopg[i]] * (loopnum-1) + loopmaxscore[loopg[i]][loopsize[loopg[i]]-1];
                if (loopmod != 0) tmp = max(tmp,loopscore[loopg[i]] * loopnum + loopmaxscore[loopg[i]][loopmod-1]);
            }
        }
        ans = max(ans,tmp);
    }

    cout << ans << '\n';

    return 0;
}