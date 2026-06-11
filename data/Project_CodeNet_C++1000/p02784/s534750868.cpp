#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,n;
  cin>>h>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  for(int i=0;i<n;i++){
    h-=a.at(i);
  }
  if(h<=0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
