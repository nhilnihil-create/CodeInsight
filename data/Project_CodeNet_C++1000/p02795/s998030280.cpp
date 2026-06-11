#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll h,w,n;
  cin >> h >> w >> n;
  int ans = n/(max(h,w));
  if(n%(max(h,w)) != 0) ans++;
  cout << ans << endl;
}