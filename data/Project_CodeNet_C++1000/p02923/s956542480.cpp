#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>h(n);
  for(int i=0;i<n;i++){
    cin>>h.at(i);
  }
  reverse(h.begin(),h.end());
  int val=0;
  int ans=0;
  for(int i=1;i<n;i++){
    if(h.at(i-1)<=h.at(i)){
      val++;
    }
    else {
      val=0;
    }
      ans=max(ans,val);
  }
    cout<<ans<<endl;
}
  
