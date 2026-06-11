#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  ll A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  if (V <= W){
    cout << "NO" << endl;
    return 0;
  }
  ll len = abs(A-B);
  ll v = V-W;
  if (len <= v*T) cout << "YES" << endl;
  else cout << "NO" << endl;
}

