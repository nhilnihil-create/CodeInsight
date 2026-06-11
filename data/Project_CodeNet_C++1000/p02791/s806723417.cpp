#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i=(int)s;i<(int)n;i++)
int main() {
  int n; cin>>n;
  vector<int> p(n,0);
  rep(i,0,n) cin>>p[i];
  int leftMin=p[0],cnt=1;
  rep(i,1,n){
    if(leftMin>=p[i]) cnt++;
    leftMin=min(leftMin,p[i]);
  }
  cout<<cnt;
}