#include <bits/stdc++.h>
using namespace std;
int main() {
  int h,n,a,s=0; cin>>h>>n;
  for(int i=0;i<n;i++) cin>>a,s+=a;
  cout<<(h>s?"No":"Yes");
}