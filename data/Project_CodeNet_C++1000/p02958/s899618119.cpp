#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,c=0; cin>>n;
  vector<int> p(n),q(n); for(int i=0;i<n;i++) cin>>p[i],q[i]=p[i];
  sort(q.begin(),q.end());
  for(int i=0;i<n;i++) if(p[i]!=q[i]) c++;
  cout<<(c<=2?"YES":"NO");
}