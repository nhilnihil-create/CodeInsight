#include <bits/stdc++.h>
using namespace std;
int n,i,a;
int main(){
  for(cin>>n;i<n+1;i++){
    a=n-i*100;
    if(0<=a&&a<=5*i)return cout<<1,0;
    if(a<0)break;
  }
  cout<<0;
}