#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, Q;// N人、Kポイント、Q回の正解
  cin >> N >> K >> Q;
  vector<int> result(N, 0);
  for (int i = 0; i < Q; i++) {
  	int answerer;
    cin >> answerer;
    result[answerer - 1] ++;
  }
  for (int i = 0; i < N; i++) {
  	if (Q - result[i] >= K) {
    	cout << "No" << endl;
    } else {
    	cout << "Yes" << endl;
    }
  }
}