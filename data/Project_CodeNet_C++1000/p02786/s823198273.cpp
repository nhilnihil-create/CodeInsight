#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll result(ll n){
  if(n==1){
    return 1;
  }
  else{
    return result(n/2)*2+1;
  }
}
int main(){
  ll a;
  cin>>a;
  cout<<result(a);
  
}