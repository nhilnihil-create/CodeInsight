#include<bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL; 
typedef long double dd; 
#define endl "\n"
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
//LL dp[2000001];
LL mod=1e9+7;
bool vis[100000];
using namespace std;
bool isPrime(LL n) {
  LL j; 
  for( j=2;j<=sqrt(n);j++){
    if(n%j==0){
      break;  
    } 
  }
  if(j>sqrt(n)){
    return 1; 
  }
  else{
    return 0; }
}
LL modexpo(LL a, LL b) {
  LL ans=1;
  a=a%mod;
  while(b>0){
    if((b&1)==1){
      ans=((ans%mod)*(a%mod))%mod;
    }
    b=b>>1;
    a=((a%mod)*(a%mod))%mod;
  }
  return ans; 
}
LL invmod(LL n){
  return modexpo(n,mod-2);
}

LL comb(LL n,LL r){
  if(r==0){
    return 1;
  }
  LL fact[n+1];
  fact[0] = 1; 
    for (LL i = 1; i <= n; i++){
       fact[i] = (fact[i - 1] * i) %mod;}
    return (fact[n] * invmod(fact[r]) % mod * invmod(fact[n - r]) % mod) %mod; 
}
LL gcd(LL a, LL b) {
  if (a == 0){
       return b;
       }  
    return gcd(b % a, a);  
}
LL lcm(LL a, LL b) {
  return (a*b)/gcd(a,b);
}
void dfs(LL i,vector<LL>adj[],bool visited[]){
  visited[i]=1;
  for(auto j:adj[i]){
    if(visited[j]==0){
      dfs(j,adj,visited);
    }
  }
}
void solve(LL k){
LL n, m; 
cin>>n>>m; 
vector<LL>adj[n+1];
bool visited[n+1];
memset(visited,0,sizeof(visited));
while(m--){
  LL a, b;
  cin>>a>>b; 
  adj[a].push_back(b);
  adj[b].push_back(a);
}
LL c=0;
for(LL i=1;i<=n; i++){
  if(visited[i]==0){
    c++;
    dfs(i,adj,visited);
  }
}
cout<<c-1<<endl; 
}
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 LL t=1;
//cin>>t;
 LL k=1;
while(k<=t){
   solve(k);
  k++;
  }
   return 0;
   }
