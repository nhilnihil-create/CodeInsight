#include <bits/stdc++.h>
using namespace std;
 
int N,M,Q,m=0;
vector<int> A(10,1),a(50),b(50),c(50),d(50);
 
 
void dfs(int n,int k){
  A.at(n)=k;
  if(n==N-1){
    int x=0;
    for(int i=0;i<Q;i++){
      if(A.at(b.at(i)-1)-A.at(a.at(i)-1)==c.at(i)){
        x+=d.at(i);
      }
    }
    m=max(x,m);
    return;
  }
  for(int i=k;i<=M;i++){
    dfs(n+1,i);
  }
  return;
}
    
 
 
int main(){
  
  cin >> N >> M >> Q;
  for(int i=0;i<Q;i++){
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
  }
  dfs(0,1);
  cout << m << endl;
  
}