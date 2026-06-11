
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

const long long int MOD = 998244353;
long long int n, nodes[200000];

int main(){
  cin >> n;
  long long int d, maxd = 0;
  bool flag = true;
  rep(i, n) nodes[i] = 0;
  rep(i, n){
    cin >> d;
    if(d == 0 && i == 0){
      nodes[0]++;
      continue;
    }else if(d == 0){
      flag = false;
      break;
    }
    nodes[d]++;
    maxd = max(d, maxd);
  }
  //rep(i, maxd + 1) cerr << nodes[i] << " "; cerr << endl;
  
  long long int sum = 1;
  for(int i = 1; i <= maxd; i++){
    long long int num = nodes[i];
    rep(j, num){
      sum *= nodes[i - 1];
      sum %= MOD;
    }
  }
  cout << (flag ? sum : 0) << endl;
  return 0;
}
