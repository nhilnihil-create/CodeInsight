#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> A(N+1);
  vector<ll> B(N);
  for(int i = 0; i <= N; i++){
    cin >> A[i];
  }
  for(int i = 0; i < N; i++){
    cin >> B[i];
  }

  ll ans = 0;
  for(int i = 0; i < N; i++){
    // iさんはA[i]をできるだけ倒す
    if(A[i] >= B[i]){
      ans += B[i];
      continue;
    } else { 
      ans += A[i];
      B[i] -= A[i];

      if(A[i+1] >= B[i]){
        ans += B[i];
        A[i+1] -= B[i];
      } else { 
        ans += A[i+1];
        A[i+1] = 0;
      }
    }
  }
  cout << ans << endl;
}
