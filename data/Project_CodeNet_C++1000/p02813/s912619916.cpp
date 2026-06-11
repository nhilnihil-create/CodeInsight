#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
  int N; cin >> N;
  int P[N]; for (int i = 0; i < N; i++) cin >> P[i];
  int Q[N]; for (int i = 0; i < N; i++) cin >> Q[i];
  int p[N]; for (int i = 0; i < N; i++) p[i] = i+1;
  int i = 0, pi, qi;
  do {
    bool is_same = true;
    for (int j = 0; j < N; j++) is_same = is_same && (p[j] == P[j]);
    if (is_same) pi=i;
    is_same = true;
    for (int j = 0; j < N; j++) is_same = is_same && (p[j] == Q[j]);
    if (is_same) qi=i;
    i++;
  } while (next_permutation(p, p+N));
  cout << abs(pi-qi) << endl;
}