#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  map<int,int> ac,wa;
  int a=0,w=0;
  rep(i,m){
    int p;string s;cin>>p>>s;
    if(s=="WA")wa[p]++;
    else {
      if(ac[p]==0){
        ac[p]++;
        a++;
        w+=wa[p];
      }
    }
  }
    cout<<a<<" "<<w<<endl;
}