#include <bits/stdc++.h>
using namespace std;

int main() {
  long N; cin >> N;
  int sqrtN = sqrt(N);
  long minAns = 1000000000000;
  for (int i =1; i<=sqrtN; i++) {
    if(N % i == 0) {
      long cand = i + N / i;
      minAns = min(cand,minAns);
    }
  }
  minAns -= 2;
  cout << minAns << endl;
}