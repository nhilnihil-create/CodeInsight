#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

ll dp[100100][13]={};

int main(void){
    string s;
    cin>>s;
    ll n=s.size();
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            for(int a=0;a<=9;a++){
                for(int j=0;j<13;j++){
                    dp[i+1][(10*j+a)%13]+=dp[i][j];
                    dp[i+1][(10*j+a)%13]%=mod;
                }
            }
        }
        else{
            int a=s[i]-'0';
            for(int j=0;j<13;j++){
                dp[i+1][(10*j+a)%13]+=dp[i][j];
                dp[i+1][(10*j+a)%13]%=mod;
            }
        }
    }
    cout<<dp[n][5]<<endl;
}