#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,M = 0;
  cin >> N >> M;
  if(N == 1 || M == 1){
    cout << "1";
  }
  else{
    cout << (N * M + 1) / 2;
  }
}
  