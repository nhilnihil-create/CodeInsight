


#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
#define DIV 1000000007
#define ll = long long
using namespace std;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;

  int count = 0;
  loop(0, 1000, n) {
    int f = 0;
    int c[3] = {n/100, (n/10)%10, n%10};
    loop(0, N, j) {
      if (c[f] == S[j]-'0') {
        f++;
      }
      if (f == 3) {
        count++;
        break;
      }
    }
  }
  print(count);
}
