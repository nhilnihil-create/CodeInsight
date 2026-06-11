#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long lint;
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(lint (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
typedef map<lint,lint> M;
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
   long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    } 
    
    const lint maxv=2005;
    struct edge{lint to;lint cost;};
    vector<vector<edge>> x(maxv);
    lint d[maxv];
    void dijkstra(lint s){    
        priority_queue<P,vector<P>,greater<P>>que;
        fill(d,d+maxv,INF);
        d[s]=0;
        que.push(P(0,s));
            while(!que.empty()){
             P p=que.top();que.pop();
             lint v=p.second;
             if(d[v]<p.first)continue;
             rep(i,x[v].size()){
                 edge e=x[v][i];
                 if(d[e.to]>d[v]+e.cost){
                     d[e.to]=d[v]+e.cost;
                     que.push(P(d[e.to],e.to));
                 }
             }   
            }
}
    //解説AC
  int main(){
     lint h,w;
     cin>>h>>w;
     char x[h][w];
     rep(i,h){
         rep(j,w){
             cin>>x[i][j];
         }
     }
     lint dp[300][300];
     rep(i,300)rep(j,300)dp[i][j]=INF;
     if(x[0][0]=='.')dp[0][0]=0;
     else dp[0][0]=1;
     rep(i,h){
         rep(j,w){
            if(i==0){
                if(j==(w-1))break;
                if (x[i][j+1]=='.')dp[i][j+1]=dp[i][j];
                else {
                    if(x[i][j]=='.')dp[i][j+1]=dp[i][j]+1;
                    else dp[i][j+1]=dp[i][j];
                }}else if(j==0){
                     if (x[i][j]=='.')dp[i][j]=dp[i-1][j];
                else {
                    if(x[i-1][j]=='.')dp[i][j]=dp[i-1][j]+1;
                    else dp[i][j]=dp[i-1][j];
                }
            }else{
                lint b,c;
                if(x[i][j]=='.')dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
                else{
                         if(x[i-1][j]=='.')b=dp[i-1][j]+1;
                    else b=dp[i-1][j];
                     if(x[i][j-1]=='.')c=dp[i][j-1]+1;
                    else c=dp[i][j-1];
                    dp[i][j]=min(b,c);
                    
                }
            }
         }
         }
         cout<<dp[h-1][w-1]<<endl;
     }
  
      
      
    

  
          
  