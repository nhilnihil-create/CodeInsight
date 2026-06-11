#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a,b;
  cin>>a>>b;
  int nearst = a/n*n;
  if(a%n==0) cout<<"OK"<<'\n';
  else{
    if(nearst+n<=b) cout<<"OK"<<'\n';
    else cout<<"NG";
  }
}