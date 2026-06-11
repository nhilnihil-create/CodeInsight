#include<iostream>
using namespace std;

int main(){
    //input
    int H,N;
    cin >> H >> N;
    int A[N+1], B[N+1];
    int i,j;
    for(i=1; i<=N; i++){
        cin >> A[i] >> B[i];
    }

    //calc
    int dp[N+1][H+1];
    for(i=0; i<=N; i++){
        dp[i][0] = 0;
    }
    for(j=1; j<=H; j++){
        dp[1][j] = (j/A[1] + (j%A[1]>0))*B[1];
    }
    for(i=2; i<=N; i++){
        for(j=1; j<=H; j++){
            if(j-A[i]<0){
                dp[i][j] = min(dp[i-1][j],B[i]);
            }else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-A[i]]+B[i]);
            }
        }
    }

    //answer
    cout << dp[N][H] << endl;
    system("pause");
    return 0;
}