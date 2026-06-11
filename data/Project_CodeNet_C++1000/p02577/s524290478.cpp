#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  unsigned long long sum=0;
  for(unsigned long long i=0;i<s.size();i++){
    sum+=s.at(i)-'0';
  }
  if(sum%9==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}