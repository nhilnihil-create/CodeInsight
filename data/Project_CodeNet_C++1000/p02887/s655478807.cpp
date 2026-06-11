#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
#define print(ans) cout << fixed << setprecision(15) << ans << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
typedef long long ll;
typedef vector<ll> vi;

int main() {
  int N, ans = 1;
  string S;
  char c;
  cin >> N;
  cin >> S;
  c = S[0];
  rep(i,N){
    if (c != S[i]){
      c = S[i];
      ans ++;
    }
  }
  print(ans);
}

