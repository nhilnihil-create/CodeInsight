#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,k,dgt=0;
  cin>>n>>k;
  while(n!=0){
    n=n/k;
    dgt++;
  }
  cout<<dgt<<endl;
}