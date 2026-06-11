#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
map<P,int> ma;
vector<int> g[1000100];
bool used[1001000];
int h[1001000];
int dp[1001000];
int main(){
  int n;cin>>n;
  int ko=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      ma[P(i,j)]=ko;
      ko++;
    }
  }
  for(int i=0;i<n;i++){
    int x[10100];
    for(int j=0;j<n-1;j++){
      cin>>x[j];x[j]--;
      if(j>=1){
        int a=i,b=x[j-1],c=i,d=x[j];
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        g[ma[P(a,b)]].push_back(ma[P(c,d)]);
        h[ma[P(c,d)]]++;
      }
    }
  }
      
  stack<int> st;
  for(int i=0;i<n*(n-1)/2;i++){
    if(h[i]==0)st.push(i);
  }
  vector<int> res;
  while(st.size()){
    int i=st.top();st.pop();
    res.push_back(i);
    for(int j:g[i]){
      h[j]--;
      if(h[j]==0)st.push(j);
    }
  }
  
  if(res.size()!=n*(n-1)/2){
    cout<<-1<<endl;
    return 0;
  }
  
  //for(int i:res)cout<<i<<endl;
  int ans=0;
  for(int i=0;i<n*(n-1)/2;i++){
    int v=res[i];
    
    for(int w:g[v]){
      dp[w]=max(dp[w],dp[v]+1);
    }
    ans=max(ans,dp[v]);
  }
  cout<<ans+1<<endl;
  return 0;
}