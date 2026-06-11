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
ll N, ans;
string S;
bool flag = true;

int main() {
  cin >> S;
  N = S.size();
  rep(i,N){
    if (i%2 == 0){
      if (S[i] != 'L'){
        continue;
      }
      else {
        flag = false;
        break;
      }
    }
    else{
      if (S[i] != 'R'){
        continue;
      }
      else{
        flag = false;
        break;
      }
      
    }
  }
  if (flag) {
    yes;
  }
  else {
    no;
  }
}

							