#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=0,a;i<n;++i){
    cin>>a;
    if(a%2==0&&a%3&&a%5)return cout<<"DENIED",0;
  }
  cout<<"APPROVED";
}