#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = n; i >= 1; i--)
    for (int j = i * 2; j <= n; j += i)
      a[i] ^= a[j];
  int ttl = 0;
  for (int i = 1; i <= n; i++)
    if (a[i])
      ttl++;
  cout << ttl << endl;
  for (int i = 1; i <= n; i++)
    if (a[i])
      cout << i << " ";
  cout << endl;
}
