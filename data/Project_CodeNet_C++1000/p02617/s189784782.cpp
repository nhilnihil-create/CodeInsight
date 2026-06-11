#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N; cin >> N;
  ll ans = 0;

  for(ll i = 0; i < N; i++){
    ans += (i+1) * (N-i);
  }
  for(int i = 0; i < N-1; i++){
    ll x,y; cin >> x >> y;
    x--; y--;
    if(x>y) swap(x,y);
    ans -= (x+1) * (N-y);
  }
  cout << ans << endl;
}
