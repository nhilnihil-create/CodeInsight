
#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
#define PI 3.14159265359
#define MOD (ll)1000000007
using namespace std;
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}


typedef long long ll;
ll INF = 1e+18;

int main() {
  int N; cin >> N;
  vector<ll> arr(N);
  rep(i, 0, N){
    cin >> arr[i];
    if(arr[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;

  rep(i, 0, N){
    ll tmp = ans * arr[i];
    if(1000000000000000000 / ans < arr[i]){
      cout << -1 << endl;
      return 0;
    }
    ans = tmp;
  }

  cout << ans << endl;

}