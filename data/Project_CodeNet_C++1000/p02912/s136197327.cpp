

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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;

    priority_queue<int, vector<int>, less<int>> q;
    loop(0, N, i) {
      int tmp;
      cin >> tmp;
      q.push(tmp);
    }

    loop(0, M, i) {
      int top = q.top() / 2;
      q.pop();
      q.push(top);
    }

    ll sum = 0;
    loop(0, N, i) {
      int nx = q.top();
      q.pop();
      sum += nx;
    }
    print(sum);
}