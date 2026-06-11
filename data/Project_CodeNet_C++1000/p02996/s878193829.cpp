#include<bits/stdc++.h>
using namespace std;

int N, A[200000], B[200000];
pair<int,int> C[200000];

signed main() {
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i] >> B[i];
  for(int i=0; i<N; i++) C[i] = make_pair(B[i], A[i]);

  sort(C, C+N);

  int t = 0;
  for(int i=0; i<N; i++) {
    auto c = C[i];
    if(t + c.second > c.first) {puts("No"); return 0;}
    t += c.second;
  }
  puts("Yes");
}
