#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M;
  cin >> N >> M;
  vector<int>vvv(N,0);
  for(int i=0; i<M; i++){
    int a,b;
    cin >> a >> b;
    a--;
    if((vvv[a] != 0 && vvv[a] != b) || (a == 0 && b == 0 && N !=1)){
      cout << -1 << endl;
      return 0;
    }
    vvv[a] = b;
  }
  if(vvv[0] == 0 && N != 1){
    vvv[0] = 1;
  }

  for(int i=0; i<N; i++){
    cout << vvv[i];
  }
  cout << endl;
}
