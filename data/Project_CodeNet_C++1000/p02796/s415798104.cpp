#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;
  vector<pair<long long, long long>> R(N);
  for(int i = 0; i < N; i++){
    long long X, L;
    cin >> X >> L;
    R.at(i) = make_pair(X + L, X - L);
  }
  sort(R.begin(), R.end());

  long long cnt = 1;
  for(int i = 1; i < N; i++){
    if(R.at(i).second < R.at(i - 1).first){
      R.at(i).first = R.at(i - 1).first;
      R.at(i).second = R.at(i - 1).second;
    }
    else cnt++;
  }
  cout << cnt << endl;
}
