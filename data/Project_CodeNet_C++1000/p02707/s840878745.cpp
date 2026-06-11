#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N, 0);
  int x;
  rep(i, N-1){
    cin >> x;
    x--;
    vec.at(x)++;
  }
  rep(i, N){
   cout << vec.at(i) << endl; 
  }
  return 0;
}