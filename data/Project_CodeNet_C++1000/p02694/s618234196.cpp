#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x,c=0,d=100; cin>>x;
  while(d<x) d+=d/100,c++;
  cout<<c;
}