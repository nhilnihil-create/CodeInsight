#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
int main(){
  int a,b,c,d,k;
  cin >> a >> b >> c >> d >> k;
  int A = a * 60 + b,B = c * 60 + d;
  B -= k;
  cout << max(0,B - A) << endl;
  return 0;
}