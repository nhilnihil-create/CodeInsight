#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  vector<pair<ll,ll>> p(n);
  rep(i,n){
    cin >> p[i].first >> p[i].second;
    swap(p[i].first, p[i].second);
  }
  sort(p.begin(),p.end());
  ll time = 0;
  rep(i,n){
    time += p[i].second;
    if(p[i].first < time){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
