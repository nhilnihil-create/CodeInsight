#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define MOD 1000000007

int main() {
  ll k;
  cin >> k;
  ll a = 0;
  rep(i,k) {
    a = 10*a+7;
    if (a%k == 0) {
      cout << i+1 << endl;
      exit(EXIT_SUCCESS);
    }
    else a = a%k;
  }
  cout << -1 << endl;
}