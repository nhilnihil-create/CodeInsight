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
  std::vector<ll> a(n);

  for(ll i; i < n; i++) cin >> a.at(i);

  sort(a.begin(), a.end());

  ll tmp = a.at(0);
  int flag = 0;

  for(ll i = 0; i < n; i++) {

    if(a.at(i) != tmp) flag++;
    tmp = a.at(i);
  }

  if(flag == 0) {
    if(a.at(0) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }
  else if(n % 3 == 0) {
    
    if(flag == 1) {
      if(a.at(n / 3 - 1) == 0 && a.at(n / 3) != 0) cout << "Yes" << endl;
      else cout << "No" << endl;
      return 0;
    }
    else if(flag == 2) {
      if(a.at(n / 3 - 1) != a.at(n / 3) && a.at(2*n / 3 - 1) != a.at(2*n / 3)) {
        int k = a.at(n / 3 - 1) ^ a.at(n / 3) ^ a.at(2*n / 3);
        if(k == 0) {
          cout << "Yes" << endl;
          
        //  cout << a.at(n / 3 - 1) << ' ' << a.at(n / 3) << ' ' << a.at(n * 2 / 3) << ' ' << k << endl;
          //cout << 1 << endl;
          return 0;
        }
        else cout << "No" << endl;
        return 0;
      }
      else {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      cout << "No" << endl;
      return 0;
    }
    
  }
  else{
    cout << "No" << endl;
    return 0;
  }
}