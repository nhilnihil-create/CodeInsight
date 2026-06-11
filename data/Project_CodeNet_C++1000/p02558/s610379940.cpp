#include<bits/stdc++.h>
#include<atcoder/dsu>

int main(){
  int n, q, p, a, b;
  scanf("%d %d", &n, &q);
  atcoder::dsu uf(n);
  for(int i=0; i<q; i++){
    scanf("%d %d %d", &p, &a, &b);
    if(p==0) uf.merge(a, b);
    else{
      if(uf.same(a, b)){
        puts("1");
      }else{
        puts("0");
      }
    }
  }
  return 0;
}