#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int64_t> cumsum(N+1);
  int64_t buf;
  for(int i=1; i<=N; i++){
    cin >> buf;
    cumsum.at(i)= cumsum.at(i-1)+ buf;
  }

  int64_t sum_all= cumsum.back();
  auto itr1= lower_bound(cumsum.begin(), cumsum.end(), sum_all/2);
  auto itr0= prev(itr1);
  int64_t sum1= *itr1;
  int64_t sum0= *itr0;

  int64_t ans= min(abs(sum_all- 2*sum1), abs(sum_all- 2*sum0));

  cout << ans << endl;
}