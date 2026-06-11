#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(){
  int n, ans=0;
  cin >> n;
  vector<int> a(n), b(n), c(n-1);
  rep(i,n) cin >> a.at(i);
  rep(i,n) cin >> b.at(i);
  rep(i,n-1) cin >> c.at(i);
  ans += accumulate(b.begin(), b.end(), 0);
  rep(i,n-1){
   if(a.at(i)==a.at(i+1)-1) ans += c.at(a.at(i)-1); 
  }
  cout << ans;
}