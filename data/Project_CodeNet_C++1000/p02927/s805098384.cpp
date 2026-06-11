#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int m,d;cin>>m>>d;
  int cnt=0;
  for(int i=1;i<=m;i++)for(int j=22;j<=d;j++){
    if((j/10)*(j%10)==i&&j%10!=1)cnt++;
  }
  cout<<cnt<<endl;
}