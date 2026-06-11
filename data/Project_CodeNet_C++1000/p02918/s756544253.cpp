#include<bits/stdc++.h>
using namespace std;

int N,K;
string S;

signed main() {
  cin >> N >> K >> S;

  vector<int> r;
  for(int i=1; i<N; i++) if(S[i]!=S[i-1])  r.push_back(i);

  if(r.size() <= K*2) cout << N -1 << endl;
  else cout << N - (r.size() - K*2) - 1 << endl;
}
