#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> red(a), green(b), blue(c);
  for (int i = 0; i < a; i++) cin >> red[i];
  for (int i = 0; i < b; i++) cin >> green[i];
  for (int i = 0; i < c; i++) cin >> blue[i];

  sort(red.begin(), red.end());
  reverse(red.begin(), red.end());
  sort(green.begin(), green.end());
  reverse(green.begin(), green.end());
  sort(blue.begin(), blue.end());
  reverse(blue.begin(), blue.end());

  ll get_red = x-1, get_green = y-1;
  ll get_blue = 0;
  ll get;
  bool redf = true, greenf = true;

  while (1) {
    //cout << get_red << " " << get_green << " " << get_blue << endl;
    if ((redf) && (greenf)) {
      get = min(red[get_red], green[get_green]);
      if (get > blue[get_blue]) break;
      else if (get == red[get_red]) get_red--;
      else get_green--;
    }
    else if (redf) {
      get = red[get_red];
      if (get > blue[get_blue]) break;
      get_red--;
    }
    else if (greenf) {
      get = green[get_green];
      if (get > blue[get_blue]) break;
      get_green--;
    }
    else break;

    get_blue++;
    if (get_blue == c) break;
    if (get_red == -1) redf = false;
    if (get_green == -1) greenf = false;
  }

  //cout << get_red << " " << get_green << " " << get_blue << endl;
  ll yum = 0;
  for (int i = 0; i <= get_red; i++) yum += red[i];
  for (int i = 0; i <= get_green; i++) yum += green[i];
  for (int i = 0; i < get_blue; i++) yum += blue[i];

  cout << yum << endl;

}
