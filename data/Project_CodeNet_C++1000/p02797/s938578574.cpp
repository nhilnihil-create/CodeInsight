#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646;
const double pi = 3.141592653589793;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  ll N, K, S;
  cin >> N >> K >> S;

  for(int i = 0 ; i < K ; i++) {
    cout << S << ' ';
  }
  for(int i = 0 ; i < N - K ; i++) {
    if(S == 1e9) {
      cout << S - 1 << ' ';
    }
    else {
      cout << S + 1 << ' ';
    }
  }


} 
