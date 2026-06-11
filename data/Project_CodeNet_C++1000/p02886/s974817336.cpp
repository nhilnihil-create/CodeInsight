#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
#define print(ans) cout << fixed << setprecision(15) << ans << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
typedef long long ll;
typedef vector<ll> vi;
int sum(vector<int> vec){
  return accumulate(vec.begin(), vec.end(), 0);
}
int main() {
  int N, ans = 0, S;
  cin >> N;
  vector<int> d(N);
  rep(i,N){
    cin >> d[i];
  }
  S = sum(d);
  rep(i, N-1){
    S -= d[i];
    ans += d[i]*S;
  }
  print(ans);
}
