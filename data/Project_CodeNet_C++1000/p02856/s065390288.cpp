#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPI(i,f,n) for(int i=(f);i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
  ll M;
  cin >> M;
  ll sum_d = 0;
  ll k = 0;
  REP(i,M) {
    ll c,d;
    cin >> d >> c;
    sum_d += (d*c);
    k += c;
  }
  cout << ((k-1)+(sum_d-1)/9) << endl;
}
