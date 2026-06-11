#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

ll f(ll x){
  if(x == 1) return 1;
  return f(x/2)*2+1;
}

int main(){
  ll h;
  cin >> h;
  cout << f(h) << endl;
}
