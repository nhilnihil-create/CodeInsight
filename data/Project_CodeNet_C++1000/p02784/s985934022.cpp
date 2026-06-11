#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  ll H, N;
  cin >> H >> N;

  ll sum =0;
  for (ll i=0 ; i<N; i++){
    ll tmp;
    cin >> tmp;
    sum += tmp;
  }

  if(sum >= H) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
