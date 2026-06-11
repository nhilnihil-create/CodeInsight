#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int pos_before;
    long long A;
}INFANT;
bool cmp(INFANT& a, INFANT& b){
    return a.A>b.A;
}
long long absval(long long n){
    return n<0?-n:n;
}
int main(){
    int N;
    cin >> N;
    int afterPos[N]={0};
    INFANT infant[N];
    long long dp[N+1][N+1];
    long long ans=0;
    for(int i=0; i<N; i++){
        cin >> infant[i].A;
        infant[i].pos_before=i;
    }
    sort(infant,infant+N,cmp);
    for(int i=0; i<N; i++){
        //cout << infant[i].pos_before << " " << infant[i].A << endl;
    }
    dp[0][0]=0;
    for(int i=1; i<=N; i++){
        dp[0][i] = dp[0][i-1] + infant[i-1].A*absval((N-i)-infant[i-1].pos_before);
        dp[i][0] = dp[i-1][0] + infant[i-1].A*absval(infant[i-1].pos_before-(i-1));
        //cout << dp[i][0] << " " << dp[0][i] << endl;
    }
    for(int xy=1; xy<=N; xy++){
        for(int x=1; x<=xy-1; x++){
            dp[xy-x][x] = max(
                dp[xy-x][x-1] + infant[xy-1].A * absval( (N-x) - infant[xy-1].pos_before ) ,
                dp[xy-x-1][x] + infant[xy-1].A * absval( infant[xy-1].pos_before - (xy-x-1) )
                );
        }
    }
  /*
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N-i; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    for(int x=0; x<=N; x++){
        ans = max(ans,dp[N-x][x]);
    }
    cout << ans;
    return 0;
}
