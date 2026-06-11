#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;
long long dp[1000010][2];
//status unsolved
long long solve(string s){

    fill((long long*)dp,(long long*)dp+sizeof(dp)/sizeof(long long),INF);

    int L=s.size();
    //dp[i][k]:=i桁目において、状態kになるための最小枚数
    //i:=桁数　
    //k=0 繰り上下がりなし　
    //k=1 繰り下がりあり
    dp[0][0]=0;

    for(int i=0;i<L;i++){

        //繰り下がり
        for(int j=0;j<2;j++){
        int D=s[i]-'0';
        D+=j;
            for(int d=0;d<10;d++){
                int b=d-D;
                int nj=0;
                if(b<0){
                    nj=1;
                    b+=10;
                }
                //次の桁の繰り下がり状態nj
                //=min(現在の値,今の桁の状態j+お客が払うコイン+お店が払うコイン)
                dp[i+1][nj]=min(dp[i+1][nj],dp[i][j]+b+d);

            }
        }
    }

    return dp[L][0];
}
int main(){
    
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    s+='0';
    cout<<solve(s)<<endl;;

    
    return 0;

}
/*


*/
