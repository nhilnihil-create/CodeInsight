#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;

  ll sum = 0;
  for (int i = 1; i <= N; i++)
  if (i % 3 != 0 && i % 5 != 0){
    sum += i;
  }
  cout << sum << endl;
}
