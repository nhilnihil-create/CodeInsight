#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
  ll pn[a+1];rep(i,a)cin>>pn[i];
  ll qn[b+1];rep(i,b)cin>>qn[i];
  ll rn[c];rep(i,c)cin>>rn[i];
  pn[a]=1e9+7;
  qn[b]=1e9+7;
  
  sort(pn,pn+a);
  sort(qn,qn+b);
  sort(rn,rn+c);
  
  int red=a-x,green=b-y,non=c;
  while (non>0) {    
    if (rn[non-1] < pn[red] && rn[non-1] < qn[green]) break;
    
    if (red < a && pn[red] <= qn[green]) {
      red++;non--;
    } else if (green < b && qn[green] <= pn[red]) {
      green++;non--;
    } else break;
    
  }
  
  ll total=0;
  for(int i=red;i<a;i++) total+=pn[i];
  for(int i=green;i<b;i++) total+=qn[i];
  for(int i=non;i<c;i++) total+=rn[i];
  cout<<total;
}
