#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int H, W;
    int K;
    cin >> H >> W >> K;
    vector<vector<char>> C(H);

    rep(i, H)rep(j, W)
    {
        char x;
        cin >> x;
        C[i].push_back(x);
    }
    uint32_t h = 0x0;
    uint32_t w = 0x0;
    int a = 0;
    int ans = 0;
    for(uint32_t h= 0; h < (1<<H); h++)for(uint32_t w = 0; w < (1<<W) ; w++)
    {
        vector<vector<char>> tmp = C;
        rep(i, H)
        {
            if(!(h&(1<<i))) continue;
            rep(j, W) tmp[i][j] = 'R';
        }
        rep(j, W)
        {
            if(!(w&(1<<j))) continue;
            rep(i, H) tmp[i][j] = 'R';
        }
        // //cout << a++ << h << w << endl;
        int cnt = 0;
        rep(i, H)rep(j, W)
        {
            if(tmp[i][j] == '#') cnt++;
        }
        if(cnt == K) ++ans;
      
    }
    cout << ans << endl;
    // rep(i, H)
    // {
    //     rep(j, W)
    //     {
    //         cout << C[i][j] ;
    //     }
    //     cout << endl;
    // }
    return 0;
}