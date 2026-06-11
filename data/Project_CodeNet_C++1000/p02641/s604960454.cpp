#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,n;
  cin>>x>>n;
  vector<int> p(n);
  vector<int> y(102,1);
  for(int i=0;i<n;i++){
    cin>>p[i];
    y[p[i]]=0;
  }
  int a=0;
  for(int i=x;i<102;i++){
    if(y[i]){
      a=i;
      break;
    }
  }
  int b=0;
  for(int i=x;i>=0;i--){
    if(y[i]){
      b=i;
      break;
    }
  }
  if(a-x>=x-b){
    cout<<b<<endl;
  }else{
    cout<<a<<endl;
  }
  return 0;
}
      
