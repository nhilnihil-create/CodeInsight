#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  int n;
  cin >> n;
  vector<P> vec;
  rep(i,n){
    ll a, b;
    cin >> a >>b;
    vec.emplace_back(P(b,a));
  }
  sort(vec.begin(), vec.end());
  ll total=0;
  for(auto p:vec){
//    cout << p.first << ' ' << p.second << endl;
    total += p.second;
//    cout << total << endl;
    if (p.first < total){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}