#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

  ll N;cin>>N;
  ll Ans=0;
  for(ll j=1;j<=N;j++){
    ll X=N/j;
    Ans += X*j*(X+1)/2;
  }
  cout<<Ans<<endl;
    
}