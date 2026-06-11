#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
vector<vi> res;int n,m,q;
int cnt  =0;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int dp [n+1][13];
    rep(i,n+1)rep(j,13)dp[i][j]=0;
    dp[0][0]=1;
    rep(i,n){
        if(s[i]=='?'){
            rep(k,10){
                rep(j,13){
                    dp[i+1][(j*10+k)%13]+=dp[i][j];
                    dp[i+1][(10*j+k)%13]%=mod;
                }
            }
        }
        else{
            int k =s[i]-'0';
            rep(j,13){
                dp[i+1][(10*j+k)%13]+=dp[i][j];
                dp[i+1][(10*j+k)%13]%=mod;
            }
    }
    
    }
    cout<<dp[n][5]<<endl;
    }