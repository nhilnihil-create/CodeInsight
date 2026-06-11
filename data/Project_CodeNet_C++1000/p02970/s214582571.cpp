#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, d;
  cin >> n >> d;

  int ans = n / (2*d+1) + 1;
  if(n % (2*d+1) == 0) --ans;

  cout <<  ans << endl;
  return 0;
}