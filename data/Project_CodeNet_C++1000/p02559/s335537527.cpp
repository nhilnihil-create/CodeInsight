#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
  // int n, m;
  // cin >> n >> m;
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  fenwick_tree<long long> fw(N);

  for (int i = 0; i < N; ++i) {
    fw.add(i,A[i]);
  }

  vector<long long> ANS;
  
  for (int i = 0; i < Q; ++i) {
    int q;
    cin >> q;
    if (q == 0) {
      int p, x;
      cin >> p >> x;
      fw.add(p, x);
    }else{
      int l, r;
      cin >> l >> r;
      ANS.push_back( fw.sum(l,r));
    }
  }

  for (int i = 0; i < ANS.size(); ++i) {
    cout << ANS[i] << "\n";
  }

  return 0;
}

