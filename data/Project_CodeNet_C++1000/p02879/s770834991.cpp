#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
int main() {

  int a,b; cin>>a>>b;
  int ans=0;

  if(a>=1&&a<=9){ans++;}
  if(b>=1&&b<=9){ans++;}
  
  if(ans==2){cout<<a*b<<endl;}
  else{cout<<-1<<endl;}
  
}