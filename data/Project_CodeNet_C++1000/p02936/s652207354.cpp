

#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    return gcd(b, a);
  }
  while (b != 0)
  {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}
void apply(vector<vector<int>> &t, vector<int> &c, vector<int> &v, int i) {
  v[i] = 1;
  for (int nextIdx : t[i]) {
    if (v[nextIdx] == 0) {
      c[nextIdx] += c[i];
      v[nextIdx] = 1;
      apply(t, c, v, nextIdx);
    }
  }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> T(N);
    vector<int> C(N);
    vector<int> V(N);
    loop(0, N-1, i) {
      int t1, t2;
      cin >> t1 >> t2;
      t1--;
      t2--;
      T[t1].push_back(t2);
      T[t2].push_back(t1);
    }

    loop(0, Q, i) {
      int j, n;
      cin >> j >> n;
      j--;
      C[j] += n;
    }

    apply(T, C, V, 0);

    loop(0, N, i) {
      if (i != N-1) {
        cout << C[i] << " ";
      } else {
        cout << C[i] << endl;
      }
    }
}