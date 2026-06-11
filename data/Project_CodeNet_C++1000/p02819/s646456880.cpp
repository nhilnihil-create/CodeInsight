#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

bool isPrime(int x){
  if(x < 2) return 0;
  else if(x == 2) return 1;
  if(x%2 == 0) return 0;
  for(int i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
  return 1;
}

int main(void){
  int X;
  cin >> X;
  while (!isPrime(X)) X++;
  cout << X << endl;
  return 0;
}
