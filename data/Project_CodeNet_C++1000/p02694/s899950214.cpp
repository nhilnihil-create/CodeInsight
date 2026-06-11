#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)
#define MOD 1000000007

//debug
#define debug(arr) cerr<<#arr<<"(l"<<__LINE__<<") : ";for(auto x:arr)cerr<<x<<" ";cerr<<endl;

int main(){
  ll X;
  ll money = 100, ans = 0;
  cin >> X;

  while(money < X){
    money += money / 100;
    ans++;
  }
  cout << ans << endl;
  return 0;
}

