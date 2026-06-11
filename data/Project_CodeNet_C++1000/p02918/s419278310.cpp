#include <bits/stdc++.h>
#include <queue>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int count=0;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  if (s.at(0)=='R'){
    if(s.at(1)=='R'){
      count++;
    }
  }
  if(s.at(n-1)=='L'){
    if(s.at(n-2)=='L'){
      count++;
    }
  }
  for(int i=1;i<n-1;i++){
    if(s.at(i)=='R'){
      if(s.at(i+1)=='R'){
        count++;
      }
    }
    else{
      if(s.at(i-1)=='L'){
        count++;
      }
    }
  }
  int ans=1;
  for(int i=1;i<n;i++){
    if(s.at(i)!=s.at(i-1)){
      ans++;
    }
  }
  if(ans==1){
    cout<<count<<endl;
    return 0;
  }
  if(ans==2){
    cout<<count+1<<endl;
    return 0;
  }
  else{
    if(ans/2<=k){
      cout<<count+ans-1<<endl;
    }
    else{
      cout<<count+2*k<<endl;
    }
  }
  

  return 0;
}
