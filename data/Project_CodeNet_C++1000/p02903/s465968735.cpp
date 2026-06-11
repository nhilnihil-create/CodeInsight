#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int H,W,A,B;
    cin >> H >> W >> A >> B;
    vector<vector<char>> G(H,vector<char>(W,'0'));
    for(int i=0;i<B;i++){
        for(int j=0;j<A;j++){
            G[i][j] = '1';
        }
    }
    for(int i=B;i<H;i++){
        for(int j=A;j<W;j++){
            G[i][j] = '1';
        }
    }
    rep(i,H){
        rep(j,W){
            cout << G[i][j];
        }
        cout << endl;
    }
    return 0;
}