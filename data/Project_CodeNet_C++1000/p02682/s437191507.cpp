#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,z,p,k;
  cin >> p >> z >> m >> k;
  int ans=0;
  ans=min(p,k);
  ans-=max(0,k-p-z);
  cout << ans << endl;
  return 0;
}