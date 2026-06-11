

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

  vector<int> A(N);
  vector<int> P(N);
  vector<int> Q(N);
  loop(0, N, i) A[i] = i+1;
  loop(0, N, i) cin >> P[i];
  loop(0, N, i) cin >> Q[i];

  int count = 1;
  int a = -1;
  int b = -1;
  do {
    bool pok = true;
    bool qok = true;
    loop(0, N, i) {
      if (A[i] != P[i]) pok = false;
      if (A[i] != Q[i]) qok = false;
    }
    if (pok) a = count;
    if (qok) b = count;
    count++;

  } while(next_permutation(A.begin(), A.end()));
  print(abs(a-b));
}
