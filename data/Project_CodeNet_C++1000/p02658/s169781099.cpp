#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,ans;
  ans=1;
  cin>>n;
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  for(int i=0;i<n;i++){
    if(a.at(i)==0){
      ans=0;
    }
  }
  for(int i=0;i<n;i++){
    if(ans!=0 && ans!=-1){
      if(1000000000000000000/ans>=a.at(i)){
        ans=ans*a.at(i);
      }else{
        ans=-1;
      }
    }
  }
  cout<<ans;
}
