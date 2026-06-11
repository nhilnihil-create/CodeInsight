#include <bits/stdc++.h>
using namespace std;

int n,m,q,ans=0;
vector<int>	a,b,c,d;

void dfs(vector<int> A){
  if(A.size() == n+1){
    int score=0;
    for(int i=0;i<q;i++){
      if(A.at(b.at(i))-A.at(a.at(i))==c.at(i)){
        score+=d.at(i);
      }
    }
    ans=max(ans,score);
    return;
  }
  
  A.push_back(A.back());
  while(A.back()<=m){
    dfs(A);
    A.back()++;
  }
}

int main(){
  cin >> n >> m >> q;
  a=b=c=d=vector<int>(q);
  for(int i=0;i<q;i++){
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
  }
  dfs(vector<int>(1,1));
  cout << ans;
}