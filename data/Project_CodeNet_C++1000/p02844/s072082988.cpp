#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main() { 
    ll N;
    string S;
    cin >> N >> S;

    ll out = 0;
    for (int i = 0; i < 1000; i++){
      int c[3] = {i / 100, (i / 10) % 10, i % 10};
      ll idx = 0;
      for (int j = 0; j < N; j++) {
        if (c[idx] + '0' == S[j]) idx++;
        if (idx == 3) break;
      }
      if (idx == 3) out++;
    }
    cout << out << endl;
    return 0;
}