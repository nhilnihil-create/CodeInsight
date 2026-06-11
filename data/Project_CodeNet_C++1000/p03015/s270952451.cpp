#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string L;
  cin >> L;
  int N = L.size();

  vector<ll> dp1(N, 0), dp2(N,0);

  dp1[0] = 1;
  dp2[0] = 2;

  for(int i = 0; i < N-1; i++){
    int num = L[i+1] - '0';
    if(num == 1){
      dp1[i+1] += dp2[i]; // 00
      dp1[i+1] %= MOD;
      dp2[i+1] += dp2[i] * 2; // 01 or 10
      dp2[i+1] %= MOD;
    } else { 
      dp2[i+1] += dp2[i]; // 00
      dp2[i+1] %= MOD;
    }
  }

  for(int i = 0; i < N-1; i++){
    dp1[i+1] += dp1[i] * 3; // 00 01 10 
    dp1[i+1] %= MOD;
  }

  cout << (dp1[N-1] + dp2[N-1]) % MOD << endl;
}
