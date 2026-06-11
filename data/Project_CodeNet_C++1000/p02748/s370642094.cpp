#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,M;
  cin>>A>>B>>M;
  vector<int> a(A);
  vector<int> b(B);
  for(int &x: a) cin>>x;
  for(int &x: b) cin>>x;
  vector<int> aa=a;
  vector<int> bb=b;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int ans=a[0]+b[0];
  for(int i=0;i<M;i++){
    int x,y,c;
    cin>>x>>y>>c; x--; y--;
    ans=min(ans,aa[x]+bb[y]-c);
  }
  cout<<ans<<endl;//O(N)で計算する
}
  