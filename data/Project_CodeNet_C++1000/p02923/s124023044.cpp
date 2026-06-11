#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,c=0,a=0; cin>>n;
  int h[n]; for(int i=0;i<n;i++) cin>>h[i];
  for(int i=1;i<n;i++){
    if(h[i-1]<h[i]) a=max(a,c),c=0;
    else c++;
  }
  cout<<max(a,c);
}