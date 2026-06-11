#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

int N;

void dfs(string S,int n){
  if(S.size()==N){
    cout<<S<<endl;
    return ;
  }
  for(int i=0;i<=n;i++){
    char c=(char)('a'+i);
    S.push_back(c);
    dfs(S,max(n,i+1));
    S.pop_back();
  }
}

int main(){
  string S;
  cin>>N;
  dfs(S,0);
}
