#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  ll n;cin>>n;
  vector<pair<int, int>> rl(n);
  fr(i,n) {
    int x, l;
    cin >> x >> l;
    rl[i].first = x+l;
    rl[i].second = x-l;
  }
  sort(rl.begin(), rl.end());
  int c = -1e9;
  int ans = 0;
  fr(i, n){
    if(c<=rl[i].second) c = rl[i].first, ans++;
  }
  
  cout << ans << endl;

  return 0;
}