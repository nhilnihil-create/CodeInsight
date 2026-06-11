#include<bits/stdc++.h>
using namespace std;

void solve() {
  int r,g,b,k,i=0;
  cin>>r>>g>>b>>k;
  while(i<k && !(r<g && g<b)) {
  	i++;
    if(r>=g)	g*=2;
    else b*=2;
  }
  if(r<g && g<b) cout<<"Yes";
  else cout<<"No";
}

int main() {
  solve();
  return 0;
}