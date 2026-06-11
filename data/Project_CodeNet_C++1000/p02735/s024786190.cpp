#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll INF = 1000000000;

ll H, W;
vector<string> A;

void DPfunc() {
    vector<ll> v(W, INF);
    vector<vector<ll>> DP(H, v);
    if(A[0][0] == '#') DP[0][0] = 1;
    else DP[0][0] = 0;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            //cout << i << " " << j << endl;
            if(i+j==0) continue;
            if(i==0) {
                if(A[i][j-1]=='.'&&A[i][j]=='#') {
                    DP[i][j] = min(DP[i][j-1]+1, DP[i][j]);
                }
                else {
                    DP[i][j] = min(DP[i][j-1], DP[i][j]);
                }
                continue;
            }
            if(j==0) {
                if(A[i-1][j]=='.'&&A[i][j]=='#') DP[i][j] = min(DP[i-1][j]+1, DP[i][j]);
                else DP[i][j] = min(DP[i-1][j], DP[i][j]);
                continue;
            }
            if(A[i-1][j]=='.'&&A[i][j]=='#') DP[i][j] = min(DP[i-1][j]+1, DP[i][j]);
            else DP[i][j] = min(DP[i-1][j], DP[i][j]);
            if(A[i][j-1]=='.'&&A[i][j]=='#') DP[i][j] = min(DP[i][j-1]+1, DP[i][j]);
            else DP[i][j] = min(DP[i][j-1], DP[i][j]);
        }
    }
    cout << DP[H-1][W-1] << endl;
}

signed main(){
    cin >> H >> W;
    A.resize(H);
    for(int i=0;i<H;i++) cin >> A[i];
    DPfunc();
    return 0;
}