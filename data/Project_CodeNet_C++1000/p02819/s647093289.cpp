#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int x; cin >> x;
  int M = 1000000;

  for(int i = x;i<M;++i){
    bool prime = true;
    for(int j = 2;j<i;++j){
      if(i%j==0){
	prime = false;
	break;
      }
    }
    if(prime){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}
