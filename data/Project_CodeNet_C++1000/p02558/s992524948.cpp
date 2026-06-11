#include <stdio.h>
#include <atcoder/dsu>

int main(){
  int N, Q;
  int t, u, v;
  scanf("%d %d", &N, &Q);
  atcoder::dsu d(N);

  for(int i = 0; i < Q; i++){
    scanf("%d %d %d", &t, &u, &v);
    if(t==0){
      d.merge(u, v);
    } else {
      if(d.same(u, v)){
        printf("1\n");
      }else{
        printf("0\n");
      }
    }
  }

  return 0;
}
