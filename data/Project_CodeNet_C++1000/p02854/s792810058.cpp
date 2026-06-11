#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n){
    cin >> a.at(i);
    sum += a.at(i);
  }
  //cout << "sum:" << sum << endl;
  
  vector<ll> s(n-1);
  vector<ll> rest(n-1);
  ll mndif = 9009009009;
  rep(i,n-1){
    if( i == 0 ) s.at(i) = a.at(i);
    else s.at(i) = s.at(i-1) + a.at(i);
    
    rest.at(i) = sum - s.at(i);
    //cout << s.at(i) << " " << rest.at(i) << endl;
    mndif = min(mndif,abs(rest.at(i)-s.at(i)));
  }
 
  cout << mndif << endl;
  return 0;
}