#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,n,c=1; cin>>n;
  vector<int> p(n),q(n),r;
  for(int i=0;i<n;i++) cin>>p[i];
  for(int i=0;i<n;i++) cin>>q[i];
  for(int i=1;i<=n;i++) r.push_back(i);  
  do{
    if(p==r) a=c;
    if(q==r) b=c;
    c++;
  }while(next_permutation(r.begin(),r.end()));
  cout<<abs(a-b);
}