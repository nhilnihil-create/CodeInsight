#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m,s=0; cin>>n>>m;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i],s+=a[i];
  sort(a.rbegin(),a.rend());
  for(int i=0;i<m;i++) if(a[i]*(4*m)<s){cout<<"No"; return 0;}
  cout<<"Yes";
}