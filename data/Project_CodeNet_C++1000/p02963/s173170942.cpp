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
  ll S;
  cin >> S;
  ll x2=0,y2=0;
  ll x1,y1,x3,y3;
  if(S<=1000000000){
    y1=S;
    x1=0;
    y3=0;
    x3=1;
  }else if(S<1000000000000000000){
    y1=1000000000;
    x3=S/1000000000+1;
    y3=1;
    x1=1000000000-S%1000000000;
  }else{
    y1=1000000000;
    x3=1000000000;
    y3=0;
    x1=0;
  }

  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
  // cout << abs((x2-x1)*(y3-y2)-(x3-x2)*(y2-y1)) << endl;
}