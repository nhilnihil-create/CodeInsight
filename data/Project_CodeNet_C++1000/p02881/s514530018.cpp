#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
#define print(ans) cout << fixed << setprecision(15) << ans << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
typedef long long ll;
typedef vector<ll> vi;

int main() {
  ll N;
  cin >> N;
  ll M;
  M = pow(N, 0.5);
  rep(i, M){
    if (N%(M-i) == 0){
      print(M-i+N/(M-i) -2);
      return 0 ;
    }
  }
  print(N-1);
}

