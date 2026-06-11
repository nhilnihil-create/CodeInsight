#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,k,s,i;
  string ans="Yes";
  cin>>n;
  k=(1<<n);
  multiset<int> ms1,ms2,ms3;
  for(i=0;i<k;i++){
    cin>>s;
    ms1.insert(s);
  }
  ms2.insert((-1)*(*prev(ms1.end(),1)));
  ms1.erase(prev(ms1.end(),1));
  for(i=0;i<n;i++){
    ms3.clear();
    for(auto j:ms2){
      auto lb=ms1.lower_bound(-j);
      if(ms1.begin()==lb){
        ans="No";
        break;
      }
      else{
        ms3.insert((-1)*(*prev(lb,1)));
        ms1.erase(prev(lb,1));
      }
    }
    if(ans=="No") break;
    else for(auto j:ms3) ms2.insert(j);
  }
  cout<<ans<<endl;
}