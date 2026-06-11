#include<iostream>
#include<string>
using namespace std;

int main() {
  int N; string S; cin >> N >> S;
  int c = 0;
  for (int b = 0; b < 1000; b++) {
    int i = 0;
    for (; i < N; i++) if (S[i] == (char)('0'+b/100)) break;
    for (i++; i < N; i++) if (S[i] == (char)('0'+b/10%10)) break;
    for (i++; i < N; i++) if (S[i] == (char)('0'+b%10)) break;
    c += (i < N);
  }
  cout << c << endl;
}