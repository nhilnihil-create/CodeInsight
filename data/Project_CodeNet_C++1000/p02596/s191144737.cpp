#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


int main() {
  int K;
  cin >> K;

  ll num = 7;
 
  vector<int> p(K);
  num = num % K;

  for(int i = 0; i < K; i++) {
    if(num == 0) { cout << i + 1; return 0; }
    if(p[num] == 0) { p[num % K] = 1; num = (num * 10 + 7) % K; }
    else break;
  }

  
  if(p[0] == 0) cout << -1 << endl;

  return 0;
}