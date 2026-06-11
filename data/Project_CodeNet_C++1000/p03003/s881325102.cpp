#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn=2000;

ll dp[maxn+1][maxn+1]={0};
ll s[maxn+1];
ll t[maxn+1];
ll n,m;
ll mod = INF;

int main(){
    
    cin >> n>>m;
    
    rep(i,n)cin >> s[i+1];
    rep(i,m)cin >> t[i+1];
    
//    for(int i=0;i<=n;i++)dp[i][0]=1;
//    for(int j=0;j<=m;j++)dp[0][j]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                dp[i][j]=(dp[i][j-1]+dp[i-1][j]+1)%mod;
                if(dp[i][j]<0)dp[i][j]+=mod;
            }else{
                dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1])%mod;
                if(dp[i][j]<0)dp[i][j]+=mod;
            }
        }
    }
    
    cout << (dp[n][m]+1)%mod<<endl;
    
    return 0;
}
