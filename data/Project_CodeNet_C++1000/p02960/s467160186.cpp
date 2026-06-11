#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e+9+7;
int main(void){
    string s;cin>>s;
    ll dp[s.size()+3][13];
    rep(i,s.size()+3)rep(j,13)dp[i][j]=0;
    dp[0][0]=1;
    rep(i,s.size()){
        char c=s[i];
        rep(j,13){
            if(c=='?'){
                rep(k,10){
                    int buf=j*10+k;
                    buf%=13;
                    dp[i+1][buf]+=dp[i][j];
                    dp[i+1][buf]%=mod;
                }
            }else{
                int k=c-'0';
                int buf=j*10+k;
                buf%=13;
                dp[i+1][buf]+=dp[i][j];
                dp[i+1][buf]%=mod;
            }
        }
    }
    ll res=dp[s.size()][5];
    cout<<res<<endl;
}