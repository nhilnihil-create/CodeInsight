#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() { 
  ll n;
  cin >> n;

  std::vector<pair<ll,ll>> ba(n);

  rep(i,n) {
    ll tmpa,tmpb;
    cin >> tmpa >> tmpb;

    ba.at(i).first = tmpb;
    ba.at(i).second = tmpa;
  }

  sort(ba.begin(), ba.end());

  ll sumtime = 0;

  rep(i,n) {
    sumtime += ba.at(i).second;
    if(sumtime > ba.at(i).first) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
