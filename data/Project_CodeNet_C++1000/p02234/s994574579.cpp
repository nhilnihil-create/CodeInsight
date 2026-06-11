#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int INF = 1000100100;


int main(){
    int n,r[101],c[101];
    cin >> n;
    for(int i=1; i<n+1; i++){
        cin >>r[i] >> c[i];
    }

    //dp[][]を初期化
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            dp[i][j]=INF;
        }
    }

    //dp[i][i]=0にする。
    for(int i=1;i<n+1;i++){
        dp[i][i]=0;
    }
    //区間幅をずらしていく。2からスタート
    for(int k=2; k < n+1; k++){
        //対象区間の始点を一つずつ見ていく
        for(int i=1; i+k -1 < n+1; i++){
            //対象区間を2つの小区間にわける
            for(int j =i; j < i+k; j++){
                dp[i][i+k-1]=min(dp[i][i+k-1], dp[i][j]+dp[j+1][i+k-1] + r[i]*c[j]*c[i+k-1]);
            }
        }//添え字が間違ってないか不安。。
    }
    //全区間の答えを出力
    cout << dp[1][n] << endl;
    return 0;
}
