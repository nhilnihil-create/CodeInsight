#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A, B, C, K;

int main(){
  cin >> A >> B >> C >> K;
  if (K <= A) cout << K << endl;
  else if (K - A <= B) cout << A << endl;
  // K <= A + B + C なので残りのケースではCからK-A-B枚選ぶことになる
  else cout << A - (K - A - B) << endl;
}