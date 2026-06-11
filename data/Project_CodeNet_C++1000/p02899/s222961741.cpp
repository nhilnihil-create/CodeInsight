#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> ans;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ans.push_back(make_pair(a,i+1));
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<n;i++){
    if(i==n-1){
      cout<<ans[i].second;
      return 0;
    }
    cout<<ans[i].second<<' ';
  }
  return 0;
}