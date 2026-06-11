#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int dp[1001][10001]; //dp[i][j]: i+1番目(1番が最初)までのダメージの合計がj以上になるように選んだ時の魔力の総和の最小値
int main(){
    int h,n,a[10000],b[10000];
    
    cin >> h >> n;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    for(int i=0; i<n+1; i++){
        for(int j=1; j<=h; j++){
            if(i==0){
                dp[i][j]= 100000001;
            }else if(j < a[i-1]){
                dp[i][j] = min(dp[i-1][j],b[i-1]);
            }else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-a[i-1]] + b[i-1]);
            }
        }
    }

    // //テスト用
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<h+1; j++){
    //         cout << right << setw(3) << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][h];


}