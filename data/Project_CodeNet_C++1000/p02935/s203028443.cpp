#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  vector<int> v(n); for(int i=0;i<n;i++) cin>>v[i];
  sort(v. begin(),v.end());
  double a=v[0];
  for(int i=1;i<n;i++) a=(a+v[i])/2;
  printf("%.6lf",a);
}