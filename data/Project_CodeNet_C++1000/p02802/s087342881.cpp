#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  map<int,int> ac,wa;
  int cnt1=0,cnt2=0;
  rep(i,m){
    int p;string s;cin>>p>>s;
    if(s=="WA")wa[p]++;
    else {
      if(ac[p]==0){
        cnt2+=wa[p];
        ac[p]=1;
        cnt1++;
      }
    }
  }
  cout<<cnt1<<" "<<cnt2<<endl;
}