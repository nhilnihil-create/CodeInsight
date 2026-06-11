#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int getgcd(int a,int b){
  int x,y; x = max(a,b); y = min(a,b);
  int c=1,r=1;
  while(y != 0 && c != 0){
    c = x / y;
    r = x % y;
    x = y; y = r;
  }
  return x;
}

int main()
{
  int K; cin >> K;
  ll sum = 0;
  FOR(a,1,K+1){
    FOR(b,1,K+1){
      FOR(c,1,K+1){
        sum += getgcd(getgcd(a,b),c);
      }
    }
  }
  cout << sum << endl;
}