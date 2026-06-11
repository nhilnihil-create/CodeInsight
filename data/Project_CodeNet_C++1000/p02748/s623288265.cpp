#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  for (int i = 0; i < A; i++)cin >> a[i];
  for (int i = 0; i < B; i++)cin >> b[i];
  int minA = *min_element(a.begin(), a.end());
  int minB = *min_element(b.begin(), b.end());
  int ans = minA + minB;
  for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    ans = min(ans, a[x-1] + b[y-1] - c);
  }

  cout << ans << endl;
  return 0;
}
