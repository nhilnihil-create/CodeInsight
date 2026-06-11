#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  long long N,Q;
  cin >> N >> Q;
  fenwick_tree<long long> A(N);
  for(int i=0;i<N;i++){
    long long a;
    cin >> a;
    A.add(i,a);
  }
  
  for(int i=0;i<Q;i++){
    long long q,x,y;
    cin >> q >> x >> y;
    
    if(q==0){
      A.add(x,y);
    }
    if(q==1){
      cout << A.sum(x,y) << endl;
    }
  }
  return 0;
}