#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }

  vector<ll> B(N+1);
  B[0] = 0;
  for(int i = 0; i < N; i++){
    B[i+1] = B[i] + A[i];
  }

  map<ll, int> m;
  ll ans = 0;
  for(int i = 0; i <= N; i++){

    if(i >= K){
      ll del = (B[i-K] - (i-K) ) % K;
      m[del]--;
    }

    ll tmp = ( B[i] -i ) % K;

    if(m.count(tmp) == 0){
      m[tmp]++;
    } else {
      ans += m[tmp];
      m[tmp]++;
    }

  }
  cout << ans << endl;
}
