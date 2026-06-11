#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,d;
  cin>>n>>d;
  int w=2*d+1;
  int ans=(n+w-1)/w;
  cout<<ans<<endl;
}