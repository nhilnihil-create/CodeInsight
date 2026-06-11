#include <atcoder/dsu>
#include <iostream>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  
  atcoder::dsu d(N);
  
  for(int i=0;i<M;i++){
    int q,u,v;
    cin >> q >> u >> v;
    if(q==0){
      d.merge(u,v);
    }else{
      if(d.same(u,v)){cout << 1 << endl;}else{cout << 0 << endl;}
    }
  }
  return 0;
}