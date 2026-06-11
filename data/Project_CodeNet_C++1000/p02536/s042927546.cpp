#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
  int N, M;
  cin >> N >> M;
  dsu D(N);
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    D.merge(a,b);
  }
  
  int cnt = 0;
  for(int i=0; i<N; i++){
    if(i == D.leader(i)){
      cnt++;
    }
  }
  
  cout << cnt - 1 << endl;
  
}
  