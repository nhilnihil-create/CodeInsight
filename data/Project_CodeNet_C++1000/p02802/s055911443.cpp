#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,p; cin>>n>>m;
  string s;
  vector<int> ac(n,0);
  vector<int> wa(n,0);
  int sumAC=0,sumWA=0;
  for(;m--;){
    cin>>p>>s;
    p--;
    if(s=="AC") ac[p]=1;
    else if(s=="WA"&&!ac[p]) wa[p]++;
  }
  for(int i=0;i<n;i++){
    sumAC+=ac[i];
    if(ac[i]) sumWA+=wa[i];
  }
  cout<<sumAC<<" "<<sumWA;
}