#include<bits/stdc++.h>

using namespace std;
using ll = long long;


ll rec(ll x){
  if(x==1) return 1;
  
  return rec(x/2)*2 +1;
}

int main(){
  ll h;
  cin >> h;

  cout << rec(h)<< endl;  
  
  return 0;
}