#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

string L;
ll dpC[100010] = { 0 };  //dpC[i] : 上からi番目まででL以下確定
ll dpUC[100010] = { 0 };

int main(){
  cin >> L;
  int len = L.size(); //桁数取得

  dpUC[0] = 1;  //初期は不確定
  for(int i = 0; i < len; i++){
    if(L[i] == '0'){  //桁が0
      dpC[i+1] = (3 * dpC[i]) % MOD;  //(1,0),(0,1),(0,0)
      dpUC[i+1] = dpUC[i] % MOD;  //(0,0)
    } else if(L[i] == '1'){
      dpC[i+1] = (dpUC[i] + 3 * dpC[i]) % MOD;  //(0,0) | (1,0), (0,1), (0,0)
      dpUC[i+1] = (2 * dpUC[i]) % MOD;  //(1,0), (0,1)
    }
  }

  cout << (dpC[len] + dpUC[len]) % MOD << endl;
  return 0;
}
