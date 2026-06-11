#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, L;
  cin >> N >> L;

  int left = L;
  int right = L + N - 1;

  int eat;
  if (right <= 0) eat = right;
  else if (left >= 0) eat = left;
  else eat = 0;

  int ans = (left + right) * N / 2 - eat;
  cout << ans << endl;
}
