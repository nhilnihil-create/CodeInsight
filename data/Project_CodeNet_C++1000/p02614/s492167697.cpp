#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>
#include <map>
#include <set>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

int solve(){

    int H,W,K;
    cin >> H >> W >> K;

    vector <string> c(H);
    REP(i,H)
    {
        cin >> c[i];
    }

    //全探索でよさそう
    //該当行、該当列は計算しない
    //どこか1列、でなく全部選ぶやつだった
    int res = 0;
    //ターゲット設定
    for(int bit_i = 0; bit_i < (1 << H); ++bit_i)
    {
        for(int bit_j = 0; bit_j < (1 << W); ++bit_j)
        {
            int cnt = 0;
            REP(x,H)
            {
                REP(y,W)
                {
                    if((1<<x) & bit_i)continue;
                    if((1<<y) & bit_j)continue;
                    if(c[x][y] == '#')++cnt;
                }
            }
            if(cnt == K)++res;
        }
    }
    cout << res << endl;



    return 0;
}

int main()
{
    solve();
    return 0;
}
