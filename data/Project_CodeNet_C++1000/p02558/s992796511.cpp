#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;

int main(){
  int N,Q;
  cin >> N;
  dsu g(N);
  cin >> Q;
  for(int i=0; i<Q; i++){
    int t,u,v;
    cin >> t >> u >> v;
    if(t == 0) g.merge(u,v);
    else cout << g.same(u,v) << endl;
  }
  return 0;
}