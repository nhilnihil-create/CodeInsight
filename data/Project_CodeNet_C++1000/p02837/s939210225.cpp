#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,x,y,k,b = 0,ans = 0,now = 0;bool ok;scanf("%d",&n);
  vector<pair<int,int>> A[n];
  for(i=0;i<n;i++){
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d%d",&x,&y);x--;
      A[i].push_back(make_pair(x,y));
    }
  }
  while(b<(1<<n)){
    ok = true;now = 0;bitset<15> B(b);
    for(i=0;i<n;i++){
      if(B[i]==0) continue;
      for(j=0;j<A[i].size();j++){
        if(A[i][j].second != B[A[i][j].first]){
          ok = false;break;
        }
      }
      if(!ok) break;
      now++;
    }
    if(ok) ans = max(ans,now);
    b++;
  }
  printf("%d\n",ans);
}