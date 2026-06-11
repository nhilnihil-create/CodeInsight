#include<bits/stdc++.h>
using namespace std;

int main() {
  int a, b; cin>>a>>b;
  if(a>b) swap(a, b);
  int diff = b-a;
  if(diff&1) 
    cout<<"IMPOSSIBLE";
  else
    cout<<diff/2 + a;
}