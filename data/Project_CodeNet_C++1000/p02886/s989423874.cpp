#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,d[110],s=0; cin>>n;
  for(int i=0;i<n;i++) cin>>d[i];
  for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) s+=d[i]*d[j];
  cout<<s;
}