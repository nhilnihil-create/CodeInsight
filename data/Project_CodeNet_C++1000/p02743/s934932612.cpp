#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = 0;
  if(c-a-b>=0){
    x=(c-a-b)*(c-a-b)-4*a*b;
    if(x>0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    cout << "No" << endl;
  }
}