#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,n;
  cin>>x>>n;
  vector<int> k(n);
  vector<bool> a(1000,true);
  for(int i=0;i<n;i++){
    cin>>k[i];
    k[i]--;
    a[k[i]]=false;
  }
  int p=0,q=0;
  for(int i=x-1;i<1000;i++){
    if(a[i]){
      p=i+1;
      break;
    }
  }
  for(int i=x-1;i>=0;i--){
    if(a[i]){
      q=i+1;
      break;
    }
  }
  if(p-x>=x-q){
    cout<<q<<endl;
  }else{
    cout<<p<<endl;
  }
  return 0;
}