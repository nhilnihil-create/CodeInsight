#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

const int N_MAX = pow(10,5);
ll fac[N_MAX+1] ={};

ll c_fac(int n) {
  if (fac[n]!=0) return fac[n];
  if (n==0) return fac[n]=1;
  return fac[n] = (c_fac(n-1)*n)%MOD;
}

int main() {
  int N; cin >> N;
  string S; cin >> S;
  ll result = 1, plus = 0;
  rep(i,2*N) {
    char now = (i%2==0) ? 'B' : 'W';
    if (S[i]==now) plus++;
    else { result *= plus; result %=MOD; plus--; }
    if (plus<0) break;
  }
  if (plus!=0) result = 0;
  else { result *= c_fac(N); result %= MOD; }
  cout << result << endl;
  return 0;
}