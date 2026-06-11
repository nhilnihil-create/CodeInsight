#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);
const ll MOD=1000000007;

string S; ll dp[100010][13];
int input()
{
    cin>>S;
}

int solve()
{
    int N=S.length();
    // for(int i=0;i<13;++i) dp[1][i]=0ll;
    // if(S[0]=='?'){
    //     for(int j=0;j<10;++j){
    //         dp[1][j]=1ll;
    //     }
    // } else {
    //     int j=S[1]-'0';
    //     dp[1][j]=1ll;
    // }
    dp[0][0]=1ll;

    for(int i=0;i<N;++i){
        if(S[i]=='?'){
            for(int j=0;j<13;++j){
                for(int k=0;k<10;++k){
                   dp[i+1][(j*10+k)%13]+=dp[i][j];
                   dp[i+1][(j*10+k)%13]%=MOD;
               }
           }
        } else {
            int k=S[i]-'0';
            for(int j=0;j<13;++j){
                dp[i+1][(j*10+k)%13]+=dp[i][j];
                dp[i+1][(j*10+k)%13]%=MOD;
            }
        }
    }
    cout<<dp[N][5]<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}