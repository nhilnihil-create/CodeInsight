#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repX(i, n ,x) for (int i = x; i < (int)(n); i++)
#define repBack(i, n) for (int i = n; i >= 0; i--)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    vector<vector<int>> wDP(H,vector<int>(W));
    rep(i,H){
        int l = 0;
        rep(j,W){
            if(S[i][j]=='#')l = 0;
            if(l == 0){
                repX(k, W, j)
                {
                    if (S[i][k] == '#')
                        break;
                    else
                        l++;
                }
            }
            wDP[i][j] = l;
        }
    }
    vector<vector<int>> hDP(H, vector<int>(W));
    rep(i, W)
    {
        int l = 0;
        rep(j, H)
        {
            if (S[j][i] == '#')
                l = 0;
            if (l == 0)
            {
                repX(k, H, j)
                {
                    if (S[k][i] == '#')
                        break;
                    else
                        l++;
                }
            }
            hDP[j][i] = l;
        }
    }
    int ans = 0;
    rep(i,H){
        rep(j,W){
            ans = max(ans,wDP[i][j]+hDP[i][j]);
        }
    }
    cout << ans-1 << endl;

    return 0;
}