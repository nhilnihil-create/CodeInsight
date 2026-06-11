#include<bits/stdc++.h>
#include<atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
int main(){
  int n, m;
  cin >> n >> m;
  fenwick_tree<long long> fn(n);
  for(int i=0; i<n; i++){
      int a;
      cin >> a;
      fn.add(i, a);
    }
  while(m--){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 0){
      fn.add(a, b);
    }else{
      cout << fn.sum(a, b) << "\n";
    }
  }
  return 0;
}
