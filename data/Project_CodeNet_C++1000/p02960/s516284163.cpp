#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(int i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7 

using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
const ll mod = 1e9+7;

ll dp[100001][13];
int main(){
    string s;
    cin>>s;
    int n=s.size();
    rep(i,13)rep(j,100001){
        dp[i][j]=0;
    }
   
    dp[0][0]=1;
    rep(i,n){
        if(s[i]=='?'){
            rep(j,13){
                rep(k,10){
                    dp[i+1][(j*10+k)%13]+=dp[i][j];
                    dp[i+1][(j*10+k)%13]%=mod;
                }
            }
        }
        else{
            rep(j,13){
                int k=s[i]-'0';
                dp[i+1][(j*10+k)%13]+=dp[i][j];
                dp[i+1][(j*10+k)%13]%=mod;
            }
        }
    }
    cout<<dp[n][5]<<endl;
    return 0;
}