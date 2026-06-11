#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m; cin >> n >> m;
  string s; cin >> s;
  
  ll now = n;
  vector<ll> move;
  bool flg = false;
  
  while(1){
    flg = false;
    for(ll dice = m; dice >= 1; dice--){
      if(now - dice < 0) continue;
      else if(s[now-dice] == '0'){
        now = now - dice;
        move.emplace_back(dice);
        flg = true;
        break;
      }
    }
    if(!flg){ cout << "-1"; return 0;}
    if(now == 0) break;
  }
  reverse(all(move));
  for(auto x : move) cout << x << " ";
  return 0;
}
