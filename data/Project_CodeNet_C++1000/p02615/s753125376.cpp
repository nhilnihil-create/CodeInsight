#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  ll N; cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  ll sum = *(A.end() - 1);
  for(int i = 2; i < N; i++){
    int tmp = i / 2;
    sum += A[N-1-tmp];
  }
  cout << sum << endl;
}
