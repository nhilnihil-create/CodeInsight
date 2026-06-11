#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,h,maxh=0; cin>>n;
  for(int i=0;i<n;i++){
    cin>>h;
    if(maxh>h){cout<<"No"; return 0;}
    maxh=max(maxh,h-1);
  }
  cout<<"Yes";
}