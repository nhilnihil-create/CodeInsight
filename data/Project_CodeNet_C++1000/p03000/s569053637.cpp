#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  int ans=1,b,now=0;
  for(int i=0;i<n;i++){
    cin >> b;
    now+=b;
    if(now<=x)
      ans++;
  }
  cout << ans << endl;
  return 0;
}