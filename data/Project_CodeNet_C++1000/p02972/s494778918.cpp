#include<iostream>
#include<list>
using namespace std;

int main() {
  int N; cin >> N;
  bool A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  bool P[N+1];
  list<int> E[N+1];
  for (int i = 1; i <= N; i++) {
    for (int j = i+i; j <= N; j+=i) {
      E[i].push_back(j);
    }
  }
  for (int i = N; i >= 1; i--) {
    bool put_ball = A[i-1];
    for (auto it = E[i].begin(); it != E[i].end(); it++) {
      put_ball ^= P[*it];
    }
    P[i] = put_ball;
  }
  int M = 0, B[N];
  for (int i = 1; i <= N; i++) {
    if (P[i]) B[M++] = i;
  }
  cout << M << endl;
  for (int i = 0; i < M; i++) cout << B[i] << endl;
}