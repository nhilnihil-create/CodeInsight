#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int num=-999;
  for(int i=0;i<n;i++){
    if(num<=h[i]-1){
      num=h[i]-1;
    }else if(num<=h[i]){
      num=h[i];
    }else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}