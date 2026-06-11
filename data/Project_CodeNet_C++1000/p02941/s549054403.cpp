#include<bits/stdc++.h>

#define maxn 100005

using namespace std;
typedef long long ll;

int main(){
  #define TASK "ABC"
 // freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  set < pair < ll, ll > > s;
  vector < ll > a(n);
  vector < ll > b(n);

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int cnt = 0;
  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    cin >> b[i];

    if (a[i] == b[i])
      cnt ++;
    else
      s.insert(make_pair(-b[i], i));
  }


  while (!s.empty() && cnt < n){
    int id = s.begin() -> second;

    int l = (id + n - 1) % n;
    int r = (id + 1) % n;

    if (b[id] < a[id])
      break;

    s.erase(s.begin());

    int ret = (b[id] - max(max(b[l], b[r]), a[id]) + b[l] + b[r] - 1) / (b[l] + b[r]);
    ret = max(ret, 1);

    b[id] -= (b[l] + b[r]) * ret;

   // cerr << b[l] << ' ' << b[id] << ' ' << b[r] << ' ' << ret << '\n';
    ans += ret;

    if (b[id] < a[id])
      break;

    if (b[id] > a[id])
      s.insert(make_pair(-b[id], id));

    if (b[id] == a[id])
      cnt++;
  }

  if (cnt < n)
    ans = -1;

  cout << ans;

  return 0;
}
