#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d,c=0,r=0; cin>>n>>d;
  do r+=2*d+1,c++; while(r<n);
  cout<<c;
}