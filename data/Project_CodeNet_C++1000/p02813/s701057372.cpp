#include <bits/stdc++.h>
#define lol long long
using namespace std;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >>n;
  vector<int> p(n),q(n),t(n);
  for(int i=0;i<n;i++) cin >>p[i],t[i]=p[i];
  for(int i=0;i<n;i++) cin >>q[i];
  sort(t.begin(),t.end());
  int P,Q;
  int i=0;
  do{
    i++;
    if(t==p) P=i;
    if(t==q) Q=i;
  }while(next_permutation(t.begin(),t.end()));
  cout <<abs(P-Q)<<'\n';
  return (0);
}