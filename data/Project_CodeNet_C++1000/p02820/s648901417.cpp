#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;

  map<char, int> point;
  point['s'] = R;
  point['p'] = S;
  point['r'] = P;

  int totalSum = 0;
  for (int i = 0; i < K; i++) {
	totalSum += point[T[i]];
    int sameCount = 0;
    for (int j = i+K; j < N; j+=K) {
      if(T[j-K]==T[j] && sameCount==0) {
		sameCount++;
        continue;
      }
      totalSum += point[T[j]];
	  sameCount = 0;
    }
  }
  
  cout << totalSum << endl;

  return 0;
}