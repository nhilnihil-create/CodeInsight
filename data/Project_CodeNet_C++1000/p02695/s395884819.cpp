#include <bits/stdc++.h>
using namespace std;;

int main() {
  int N,M,Q; cin >> N >> M >> Q; 
  vector<tuple<int,int,int,int>> mat(Q);
  for (int i =0; i<Q; i++) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    mat.at(i) = make_tuple(a,b,c,d);
  }

  int ans =0;  
  for (int tmp = 1; tmp <= (1 << N+M-1); tmp++) {
    bitset<19> bit(tmp);
    int bit1 = bit.count();
    if (bit1 != N) continue;
    vector<int> A;
    int p =1;
    for (int i =N+M-2; i>=0; i--) {
      if (bit.test(i)) {
        A.push_back(p);
      } else {
        p++;
      }
    }
    int ansD =0;
    for (int i =0; i<Q; i++) {
      int a,b,c,d;
      tie(a,b,c,d) = mat.at(i);
      if (A.at(b-1) - A.at(a-1) == c) ansD += d;
    }
    ans = max(ansD,ans);
  }
  cout << ans << endl; 
}
  