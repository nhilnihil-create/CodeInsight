#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,k;
  cin >> n >> k;
  int ans=0;
  if(k==1) ans=0;
  else ans=n-k;

  cout << ans << endl;
  return 0;
}
