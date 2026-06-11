#include<bits/stdc++.h>
using namespace std;
int main() {
  long long N, P; cin >> N >> P;
  string S; cin >> S;
  long long count = 0;
  if(P == 2 || P == 5) {
    for(long long i = 0; i < N; i++) {
      if((S.at(i) - '0') % P == 0) {
        count += (i + 1);
      }
    }
    cout << count << endl;
    return 0;
  }
  vector<long long> mods(P, 0);
  long long d = 1, m = 0;
  for(long long i = 0; i < N; i++) {
    m = ((S.at(N - 1 - i) - '0') * d + m) % P;
    //cout << m << endl;
    mods.at(m)++;
    d *= 10; d %= P;
  }
  mods.at(0)++;
  for(long long i = 0; i < P; i++) {
    count += (mods.at(i) * (mods.at(i) - 1) / 2);
  }
  cout << count << endl;
}