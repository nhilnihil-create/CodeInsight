#include <bits/stdc++.h>

using namespace std;

#define ll long long 
int main(){
  
  
  ll n;
  cin>>n;
  ll k;
  cin>>k;
  
  ll temp = n*500;
  if(temp < k  ){
    cout<<"No";
  }
  else
    cout<<"Yes";
  
  return 0 ;
}
