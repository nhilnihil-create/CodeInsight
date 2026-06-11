#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll a;
  double b;
  cin >> a >> b;
  ll bi = b * 100 + 0.5;
  a *= bi;
  a /= 100;
  cout << a << endl;
  return 0;
}