#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll count(ll m){
  if(m == 1){
    return 1;
  } else{
    return 1 + 2*count(m/2);
  }
}

int main(){
  ll H;
  cin >> H;

  cout << count(H) << "\n";
  
  
  return 0;
}
