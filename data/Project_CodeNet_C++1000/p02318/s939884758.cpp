#include<iostream>
#include<string>
using namespace std;

const int INF = 1<<29;
int dp[1005][1005]; //d[i][j]:=s1...siとt1...tjの編集距離

int main(){
    string X, Y;
    cin >> X;
    cin >> Y;

    for(int i=0; i<=X.size(); i++)for(int j=0; j<=Y.size(); j++) dp[i][j] = INF;
    for(int i=0; i<=X.size(); i++) dp[i][0]=i;
    for(int i=0; i<=Y.size(); i++) dp[0][i]=i;

    for(int j=0; j<X.size(); j++){
        for(int k=0; k<Y.size(); k++){
            int cost = (X[j]==Y[k])?0:1;
            dp[j+1][k+1] = min(dp[j][k]+cost, min(dp[j][k+1], dp[j+1][k])+1);
        }
    }
    cout << dp[X.size()][Y.size()] << endl;
}

