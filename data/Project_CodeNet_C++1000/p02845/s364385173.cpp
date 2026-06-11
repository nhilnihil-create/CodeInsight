#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
#define MOD 1000000007
using namespace std;
  
int N, C[3];
ll sum = 1;

int main() {
  cin >> N; 
  ll A[N]; rep(i,1,N+1) cin >> A[i];
  
  rep(i,1,N+1) {
    ll cnt = 0, id = -1;
    if (A[i] == C[0]) { cnt++; id = 0; }
	if (A[i] == C[1]) { cnt++; id = 1; }
    if (A[i] == C[2]) { cnt++; id = 2; }
    if (id == -1) {
      cout << "0" << endl;
      return 0;
    }
    sum *= cnt; C[id]++;
    sum %= 1000000007;
  }
  cout << sum << endl;
}