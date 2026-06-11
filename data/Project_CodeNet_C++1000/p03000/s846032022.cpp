#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  int length[n];
  for(int i=0; i<n; i++) cin>>length[i];

  int ans = 1;
  int posi = 0;
  for(int i=0; i<n; i++) {
    posi += length[i];
    if(posi<=x) ans++;
    else break;
  }

  cout<<ans<<endl;

  return 0;
}