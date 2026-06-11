#include<iostream>
#include<stack>
using namespace std;
 
int div(int A, int B, int mod_p) {
  stack<int> q_stack;
  int a = B, b = mod_p, r;
  while (b) {
    q_stack.push(a / b);
    r = a % b; a = b; b = r;
  }
  long u = 1, v = 0;
  while (!q_stack.empty()) {
    int q = q_stack.top(); q_stack.pop();
    long u1 = v, v1 = u-q*v; u = u1 % mod_p; v = v1 % mod_p;
  }
  return (long)A * (u + mod_p) % mod_p;
}

int main() {
  int DIV = 1e+9 + 7;
  int N, K; cin >> N >> K;
  int A[K+1], B[K];
  A[0] = 0; A[1] = N - K + 1; B[0] = 1;
  for (int i = 1; i < K; i++) {
    A[i+1] = div((long)A[i] * (N-K+1-i) % DIV, i+1, DIV);
    B[i] = div((long)B[i-1] * (K-i) % DIV, i, DIV);
  }
  for (int i = 0; i < K; i++) {
    cout << (long)(A[i+1]+DIV) * B[i] % DIV << endl;
  }
}