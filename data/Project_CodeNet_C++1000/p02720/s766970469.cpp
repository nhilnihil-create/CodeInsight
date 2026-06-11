#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void){
  int k; cin>>k;
  queue<ll> qu;
  for(int i=1; i<=9; ++i) qu.push(i);
  while(--k){
    ll a=qu.front();
    if(a%10>0) qu.push(a*10+a%10-1);
    qu.push(a*10+a%10);
    if(a%10<9) qu.push(a*10+a%10+1);
    qu.pop();
  }
  cout<<qu.front();
  return 0;
}