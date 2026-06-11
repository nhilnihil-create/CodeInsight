#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  int N,K;
  cin>>N>>K;
  if (K > (N-1)*(N-2)/2){
    cout << -1 << endl;
    return 0;
  }
  int tmp = (N-1)*(N-2)/2 - K;
  cout << tmp + N-1 << endl;
  for(int i(2);i<=N;i++){
    cout << 1 << " " << i << endl;
  }
  for(int i(2);i<=N;i++){
    for(int j(i+1);j<=N;j++){
      if(tmp==0)break;
      tmp--;
      cout << i << " " << j << endl;
    }
  }
  return 0;
}

