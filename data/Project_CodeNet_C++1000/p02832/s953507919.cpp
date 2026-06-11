#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0;
  int p=1;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(a==p) p++;
    else ans++;
  }
  if(p==1) cout << -1 << endl;
  else cout << ans << endl;
}