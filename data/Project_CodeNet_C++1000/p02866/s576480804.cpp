#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  const ll MOD = 998244353;
  int N;
  cin >> N;
  vll D(N);
  rep(i, N)cin >> D[i];
  ll far = *max_element(D.begin(), D.end());
  vll a(far+1, 0);
  rep(i, N)a[D[i]]++;
  ll ans = 1; 
  rep(i, far){
    rep(j, a[i+1]){
      ans *= a[i];
      ans %= MOD;
    }
  }
  if (D[0] != 0 || a[0] != 1) ans = 0;
  cout  << ans << endl;
}