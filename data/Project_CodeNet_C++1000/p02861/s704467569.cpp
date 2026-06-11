


#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
#define ll long long
using namespace std;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  loop(0, N, i) {
    int x, y;
    cin >> x >> y;
    A[i] = make_pair(x, y);
  }
  sort(A.begin(), A.end());

  double total = 0;
  int count = 0;
  do {
    loop(1, N, i) {
      int vx = A[i].first - A[i-1].first;
      int vy = A[i].second - A[i-1].second;
      total += sqrt(vx*vx + vy*vy);
    }
    count++;
  } while(next_permutation(A.begin(), A.end()));
  cout << fixed << setprecision(9) << total/count << endl;
}
