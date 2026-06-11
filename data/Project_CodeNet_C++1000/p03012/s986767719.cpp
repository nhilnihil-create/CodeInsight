#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i=(int)s;i<(int)n;i++)
int main() {
  int n,w[110],a=110; cin>>n;
  rep(i,0,n) cin>>w[i];
  rep(i,0,n){
    int s1=0,s2=0;
    rep(j,0,i+1) s1+=w[j];
    rep(j,i+1,n) s2+=w[j];
    a=min(a,abs(s1-s2));
  }
  cout<<a;
}