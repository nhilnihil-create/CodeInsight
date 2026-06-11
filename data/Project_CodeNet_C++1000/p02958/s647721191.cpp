#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,c=0,p; cin>>n;
  for(int i=0;i<n;i++){cin>>p; if(p!=i+1) c++;}
  cout<<(c<=2?"YES":"NO");
}