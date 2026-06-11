#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<long long> A(N);
  for(auto& x: A){
    cin >> x;
  }

  vector<long long> A_sum(N + 1);
  for(int i = 0; i < N; i++){
    A_sum[i + 1] = A[i] + A_sum[i];
  }

  auto itr = lower_bound(A_sum.begin(), A_sum.end(), A_sum[N] / 2);
  //cout << *prev(itr) << endl;
  long long ans = min(abs(A_sum[N] - 2 * (*itr)), abs(A_sum[N] - 2 * *prev(itr)));
  cout << ans << endl;
}

