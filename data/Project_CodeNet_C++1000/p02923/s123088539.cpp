#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  int ans=0;
  int count=0;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  reverse(h.begin(),h.end());
  for(int i=1;i<n;i++){
    if(h[i-1]<=h[i]){
      count++;
    }
    else{
      count=0;
    }
    ans=max(ans,count);
  }
  cout<<ans<<endl;
}