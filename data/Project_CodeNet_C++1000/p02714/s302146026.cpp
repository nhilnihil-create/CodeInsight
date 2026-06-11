#include <iostream>
#include <string>
using namespace std;

int main() {
  long long N; cin >> N;
  string S; cin >> S;
  long long R = 0, G = 0, B = 0;
  long long T = S.size();
  for (long long i = 0; i < T; i++){
    if (S[i] == 'R') R++;
    if (S[i] == 'G') G++;
    if (S[i] == 'B') B++;
  }
  long long count = R * G * B;
  for (long long i = 0; i < N; i++){
    for (long long j = i; j < N; j++){
      if (2 * j - i > N - 1) continue;
      if (S[i] != S[j] && S[i] != S[2 * j - i] && S[j] != S[2 * j - i]) count--;
    }
  }
  cout << count << endl;
}