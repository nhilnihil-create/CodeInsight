#include<bits/stdc++.h>
using namespace std;

int main(){
  string n;
  cin>>n;
  int sum=0;
  for(int i=0;i<n.size();i++){
    sum+=n.at(i)-'0';
    sum%=9;
  }
  if(sum==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}