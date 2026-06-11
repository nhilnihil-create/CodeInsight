#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n, k;
  cin >> n >> k;
  vi a(n+1);
  for(int i=1; i<=n; i++) cin >> a[i];
  vector<bool> ok(n+1,false);
  vi remember(n+1);
  remember[1] = 0;
  int here = 1; ok[here] = true;
  for(ll i=1; i<=k; i++){
    here = a[here];
    if(ok[here]){
      ll nokori = (k-i)%(i-remember[here]);
      i = k-nokori;
    }
    remember[here] = i;
    ok[here] = true;
  }
  cout << here << endl;
}
