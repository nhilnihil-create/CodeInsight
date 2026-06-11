#include <bits/stdc++.h>
using namespace std;
using P= pair<int,int>;

int main(){
  int n; cin>>n;
  int num[n];
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  sort(num,num+n);
  vector<P> ans;
  int max=num[n-1],min=num[0];
  for(int i=1;i<n-1;i++){
    if(num[i]<0){
      ans.push_back(P(max,num[i]));
      max-=num[i];
    }else{
      ans.push_back(P(min,num[i]));
      min-=num[i];
    }
  }
  ans.push_back(P(max,min));
  cout<<max-min<<endl;
  for(int i=0;i<n-1;i++){
    cout<<ans[i].first<<' '<<ans[i].second<<endl;
  }
}