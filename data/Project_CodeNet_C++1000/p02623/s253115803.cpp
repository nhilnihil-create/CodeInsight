#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;
  ll K; cin >> K;
  vector<ll> A(N+1,0), B(M+1,0);

  for(int i = 1; i <= N; i++){
    ll tmp = 0; cin >> tmp;
    A[i] = tmp + A[i-1];
  }

  for(int i = 1; i <= M; i++){
    ll tmp = 0; cin >> tmp;

    B[i] = tmp + B[i-1];
  }


  int max_val = 0;
  for(int i = 0; i <= N; i++){
    ll time = A[i]; 
    ll r = K - A[i];

    if(r < 0) break;

    int index = upper_bound(B.begin(), B.end(), r) - B.begin() - 1;
    max_val = max(max_val, i + index);
  }
  cout << max_val << endl;

}
