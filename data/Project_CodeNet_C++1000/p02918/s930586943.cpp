#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,cnt=0; string s; cin >>n >>k >>s;
  for(int i=0; i<n-1; i++) if(s[i]!=s[i+1]) cnt++;  
  if(k<=cnt/2) cout <<n-1-cnt+2*k;
  else cout <<n-1;
return 0;}