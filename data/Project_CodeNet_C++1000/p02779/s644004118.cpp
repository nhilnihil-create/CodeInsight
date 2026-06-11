#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);

  for(ll i=0; i< N; i++){
    cin >>A[i];
  }

  sort(A.begin(), A.end());

  for(ll i=0; i< N-1; i++){
    if(A[i] == A[i+1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
