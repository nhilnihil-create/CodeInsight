#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

int main() { 
    cin >> N >> S;
    S.push_back('%');
    ll out = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] == S[i + 1]) {
        continue;
      } else {
        out++;
      }
    }
    cout << out << endl;
    return 0; 
}