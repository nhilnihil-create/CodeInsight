#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,w[110],a=110,s1=0,s2=0; cin>>n;
  for(int i=0;i<n;i++) cin>>w[i],s2+=w[i];
  for(int i=0;i<n-1;i++) s1+=w[i],s2-=w[i],a=min(a,abs(s1-s2));
  cout<<a;
}