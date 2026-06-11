#include <bits/stdc++.h>  
using namespace std;

int main() {
  int n,d; cin>>n>>d;
  int t=2*d+1;
  int ans=n/t+(n%t==0 ? 0:1);
  cout<<ans;
}

