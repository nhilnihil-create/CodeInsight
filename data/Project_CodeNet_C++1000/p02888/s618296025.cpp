#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 0;
  cin >> n;
  vector<int>l(n);
  rep(i,0,n) cin >> l[i];
  sort(l.begin(),l.end());
  rep(i,0,n-2) rep(j,i+1,n-1) rep(k,j+1,n){
    if(l[k] < l[i]+l[j]) ans++;
    else break;
  }
  cout << ans << endl;
}