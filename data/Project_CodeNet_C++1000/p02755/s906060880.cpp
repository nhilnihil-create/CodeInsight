#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A= 0, B=0, ans=-1;
  cin >> A >> B;

  for (int i=B*10; i<10*(B+1); i++){
    if ((i * 8)/100 == A){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}