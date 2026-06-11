#include<bits/stdc++.h>
using namespace std;
bool is_prime(int X){
  if(X <= 1){
    return false;
  }
  for(int i = 2;(i * i) <= X;i++){
    if(X % i == 0){
      return false;
    }
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int X;
  cin>>X;
  int p = X;
  while(!is_prime(p)){
    p++;
  }
  cout<<p<<'\n';
}