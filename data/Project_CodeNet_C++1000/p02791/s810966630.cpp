#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>p(n);
  for(int i=0;i<n;i++)cin>>p[i];
  
  int x=p[0];
  int cnt=1;
  
  for(int i=1;i<n;i++){
    if(p[i]<x){
      x=p[i];
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
