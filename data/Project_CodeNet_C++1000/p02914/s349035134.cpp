#include<bits/stdc++.h>

#define maxn 100005

using namespace std;
typedef long long ll;

int n;
ll a[maxn];

int main(){
  #define TASK "ABC"
//  freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
  ios_base::sync_with_stdio(0);

  cin >> n;

  ll sumxor = 0, maxbit = 60;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sumxor ^= a[i];
  }

  for (int i = 0; i < n; ++i)
    a[i] &= ~sumxor;

  int index = 0;

  for (int i = maxbit; i >= 0; --i) {
    int id = -1;

    for (int j = index; j < n; ++j)
      if ((a[j] >> i)&1)
        id = j;

    if (id == -1) continue;

    swap(a[id], a[index]);

    for (int j = 0; j < n; ++j)
      if ((a[j] >> i)&1 && j != index)
        a[j] ^= a[index];

    index++;
  }

  ll ret = 0;

  for (int j = 0; j < n; ++j)
    ret ^= a[j];

  cout << ret + (ret ^ sumxor);
  return 0;
}
