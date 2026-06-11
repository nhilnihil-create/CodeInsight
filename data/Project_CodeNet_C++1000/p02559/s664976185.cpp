#include <atcoder/fenwicktree>
#include <cstdio>

using namespace std;
using namespace atcoder;


int main(){
  int n, q;
  scanf("%d %d", &n, &q);
  
  fenwick_tree<long long> fw(n);
  for (int i = 0; i < n; i ++) {
    int a;
    scanf("%d", &a);
    fw.add(i, a);
  }
  
  for (int i = 0; i < q; i ++) {      
    int t, u, v;
    scanf("%d %d %d", &t, &u, & v);
    if (t == 0){
      fw.add(u, v);
    }
    else{
      printf("%lld\n", fw.sum(u, v));
    }
    
  }
    
  return 0;
  
}  