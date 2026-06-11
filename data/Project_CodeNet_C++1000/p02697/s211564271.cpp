#include <bits/stdc++.h>
using namespace std;
//解答写し
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>ans;
  if(n%2==1){
    for(int l=1,r=n-1;l<r;l++,r--){
      ans.emplace_back(l,r);
    }
  }else{
    bool flag=false;
    for(int l=1,r=n-1;l<r;l++,r--){
      if(!flag && r-l<=n/2){
        --r;
        flag=true;
      }
      ans.emplace_back(l,r);
    }
  }
  for(int i=0;i<m;i++){
   printf("%d %d\n",ans[i].first,ans[i].second);
  }
  return 0;
}