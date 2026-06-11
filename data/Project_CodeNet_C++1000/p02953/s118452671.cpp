#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  int pre=-999;
  for(int i=0;i<n;i++){
    if(pre<=a.at(i)-1){
      pre=a.at(i)-1;
    }
    else if(pre<=a.at(i)){
      pre=a.at(i);
    }
    else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
