#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
#define print(ans) cout << fixed << setprecision(15) << ans << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N,K,Q, ans = 0;
string S;
bool flag = true;


int main() {
  cin >> N >> K >> Q;
  vector<ll> B(N);
  ll a;
  rep(i, Q){
    cin >> a;
    B[a-1] ++;
  }
  rep(i,N){
    if (B[i] - Q + K > 0){
      yes;
    }
    else{
      no;
    }
  }
}


