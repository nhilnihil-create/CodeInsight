#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N,Q,sum=0;
  cin >> N;
  vector<int>vec(N),V(100005,0);
  for(int i=0; i<N; i++){
	  cin >> vec[i];
	  sum += vec[i];
	  V[vec[i]]++;
  }
  cin >> Q;
  for(int i=0; i<Q; i++){
	  int a,b;
	  cin >> a >> b;
	  sum = sum-((a-b)*V[a]);
      cout << sum << endl;
      V[b] += V[a];
      V[a] = 0;
  }
}
