#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int H, W;
int MAP[2000][2000];
int dp_l[2000][2000];
int dp_r[2000][2000];
int dp_u[2000][2000];
int dp_d[2000][2000];
int main(void){
    cin >> H >> W;
    char c;
    REP(h, H) REP(w,W){
        cin >> c;
        if (c=='#') MAP[h][w] = 1;
    }
    REP(h, H){
        int count = 0;
        for(int w=W-1;w>=0;w--){
            if(MAP[h][w]==0) dp_l[h][w] = count++;
            else count = 0;
        }
    }
    REP(h, H){
        int count = 0;
        REP(w, W){
            if(MAP[h][w]==0) dp_r[h][w] = count++;
            else count = 0;
        }
    }

    REP(w, W){
        int count = 0;
        for(int h=H-1;h>=0;h--){
            if(MAP[h][w]==0) dp_u[h][w] = count++;
            else count = 0;
        }
    }
    REP(w, W){
        int count = 0;
        REP(h, H){
            if(MAP[h][w]==0) dp_d[h][w] = count++;
            else count = 0;
        }
    }

    int res = 0;
    REP(h,H) REP(w,W){
        if(MAP[h][w]==0) res = max(res, 1+dp_l[h][w]+dp_r[h][w]+dp_u[h][w]+dp_d[h][w]);
    }
    cout << res << endl;
    return 0;
}

