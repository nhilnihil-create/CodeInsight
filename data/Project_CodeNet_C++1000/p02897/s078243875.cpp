#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  double o=0, e=0;
  for(int i=1;i<=n;i++) {
    if(i&1) o++;
    else e++;
  }
  double ans = o/n;
  cout<<fixed<<setprecision(9)<<ans;
}