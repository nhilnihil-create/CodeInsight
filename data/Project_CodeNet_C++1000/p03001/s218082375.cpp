#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll w, h, x, y;
  cin>>w>>h>>x>>y;
  
  double area = ((double)w*h)/2;
  if(w==2*x && h==2*y) cout<<area<<" "<<1<<endl;
  else cout<<area<<" "<<0<<endl;
}