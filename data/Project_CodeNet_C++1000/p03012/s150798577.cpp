#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> W(N);
  int sum = 0;

  rep(i,N){
    cin >> W[i];
    sum += W[i];
  }

  int mini = sum;
  int prefix_sum = 0;
  rep(i, N){
    cin >> W[i];
    prefix_sum += W[i];
    mini = min(mini, abs(prefix_sum - (sum - prefix_sum)));
  }

  cout << mini << endl;
}
