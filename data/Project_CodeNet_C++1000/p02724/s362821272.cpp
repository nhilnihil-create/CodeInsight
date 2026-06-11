#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N; cin >> N;
  ll ans = 0;
  ll tmp1 = N / 500;
  N -= 500 * tmp1;
  ans += tmp1 * 1000;

  ll tmp2 = N / 5;
  ans += tmp2 * 5;

  cout << ans << endl;
}
