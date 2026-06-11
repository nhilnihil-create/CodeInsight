#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,m;cin>>a>>b>>m;
  vector<int> A(a),B(b);
  int aa=1e9,bb=1e9;
  rep(i,a){
    cin>>A[i];
    aa=min(aa,A[i]);
  }
  rep(i,b){
    cin>>B[i];
    bb=min(bb,B[i]);
  }
  int cnt1=aa+bb;
  rep(i,m){
    int x,y,c;cin>>x>>y>>c;
    x--;y--;
    int cnt2=A[x]+B[y]-c;
    cnt1=min(cnt1,cnt2);
  }
  cout<<cnt1<<endl;
}