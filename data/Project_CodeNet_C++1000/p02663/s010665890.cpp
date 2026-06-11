#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int H1,M1,H2,M2,K; cin >>H1 >>M1 >>H2 >>M2 >>K;
  int okiru=H1*60+M1;
  int neru=H2*60+M2;
  cout <<neru-okiru-K <<endl;
  return 0;
}
