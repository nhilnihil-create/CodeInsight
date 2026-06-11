#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,p[22],a=0; cin>>n,p[0]=1,p[1]=2;
  for(int i=0;i<n;i++) cin>>p[i];
  for(int i=1;i<n-1;i++) if((p[i-1]<p[i]&&p[i]<p[i+1])||(p[i-1]>p[i]&&p[i]>p[i+1])) a++;
  cout<<a;
}