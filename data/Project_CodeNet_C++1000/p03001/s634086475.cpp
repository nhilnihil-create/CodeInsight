#include <bits/stdc++.h>
using namespace std;
#define ll long long
using  P=pair<ll,ll>;
int main(){
  long double W,H,x,y;
  cin>>W>>H>>x>>y;
  cout<<H*W/2<<" ";
  if(2*x==W && 2*y==H){cout<<1<<endl;}
  else{cout<<0<<endl;}
}