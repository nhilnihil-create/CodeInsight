#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  ll n,h;
  cin >> h >> n;
  ll x,s = 0;
  rep(i,n){
    cin >> x;
    s += x;
  }
  cout << (s >= h ? "Yes" : "No") << endl;

  return 0;
}
