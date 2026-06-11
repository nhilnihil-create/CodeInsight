#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
  ll h,n;
  cin>>h>>n;
  ll sum=0;
  vector<ll>a(n);
  for(int i=0;i<n;i++){

    cin>>a[i];
    sum=sum+a[i];
  }
  if(sum>=h)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;}
  
