#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int K, X;
  cin >> K >> X;

  for (int i = X - (K - 1); i <= X + (K - 1); i++){
    cout << i << " ";
  }
}
