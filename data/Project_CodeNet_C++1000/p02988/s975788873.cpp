#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>p(n);
  rep(i,0,n) cin >> p[i];
  int ans = 0;
  rep(i,1,n-1){
    if(p[i] > p[i-1] && p[i] <= p[i+1]) ans++;
    else if(p[i] <= p[i-1] && p[i] > p[i+1]) ans++;
  }
  cout << ans << endl;
}