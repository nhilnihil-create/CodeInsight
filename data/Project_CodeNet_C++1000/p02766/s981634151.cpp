#include <bits/stdc++.h>
using namespace std; 
int main() {
  int n,k,c=1; cin>>n>>k;
  while(n>=k) n/=k,c++;
  cout<<c;
}