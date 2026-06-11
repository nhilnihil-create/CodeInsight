#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int m;
  cin >> m;
  ll sum = 0, num = 0;
  for (int i = 0; i < m; i++) {
    ll d, c;
    cin >> d >> c;
    sum += (d * c);
    num += c;
  }

  ll ans = num - 1 + ((sum - 1) / 9);
  cout << ans << '\n';
}
