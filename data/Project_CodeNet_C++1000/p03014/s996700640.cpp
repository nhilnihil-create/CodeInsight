#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007
typedef vector<vector<int>> Graph; 
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    Graph L(H,vector<int>(W)),R(H,vector<int>(W)),U(H,vector<int>(W)),D(H,vector<int>(W));
    rep(i,H){
        if(S[i][0]=='.'){
            L[i][0]=1;
        }
        for(int j=1;j<W;j++){
            if(S[i][j]=='.'){
                L[i][j] = L[i][j-1] + 1;
            }else{
                L[i][j] = 0;
            }
        }
        if(S[i][W-1]=='.'){
            R[i][W-1]=1;
        }
        for(int j=W-2;j>=0;j--){
            if(S[i][j]=='.'){
                R[i][j] = R[i][j+1] + 1;
            }else{
                R[i][j] = 0;
            }
        }
    }
    rep(i,W){
        if(S[0][i]=='.'){
            U[0][i]=1;
        }
        for(int j=1;j<H;j++){
            if(S[j][i]=='.'){
                U[j][i] = U[j-1][i] + 1;
            }else{
                U[j][i] = 0;
            }
        }
        if(S[H-1][i]=='.'){
            D[H-1][i]=1;
        }
        for(int j=H-2;j>=0;j--){
            if(S[j][i]=='.'){
                D[j][i] = D[j+1][i] + 1;
            }else{
                D[j][i] = 0;
            }
        }
    }

    int ans = 0;
    rep(i,H)rep(j,W){
        int tmp;
        //cout << L[i][j] << " " << R[i][j] << " " << U[i][j] << " " << D[i][j] << endl;
        tmp = L[i][j]+R[i][j]+U[i][j]+D[i][j]-3;
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}