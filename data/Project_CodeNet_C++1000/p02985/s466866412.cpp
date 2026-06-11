#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> g(100010);

vector<bool> vis(100010);

int k;

long long  dfs(int s){
  long long int res=k;
  
  stack<int> st;
  
  st.push(s);
  
  vis[s]=true;
  
  while(!st.empty()){
    
    int p=st.top();
    
    st.pop();
    
    int ans=0;
    
    for(auto x:g[p]){
      if(!vis[x]){
        if(p==s){
          res*=(k-1-ans);
        }
        else{
          res*=(k-2-ans);
        }
        
        res %=1000000007;
        vis[x]=true;
        ans++;
        st.push(x);
      }
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n >> k;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << dfs(0) << endl;
}
