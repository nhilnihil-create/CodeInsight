#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
全部がそれぞれ素pairwise
全部に共通して割れればnot coprime
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N;
  cin >> N;
  vector<ll> used(1000010, 0);
  rep(i, N){
    ll A;
    cin >> A;
    for(ll i=2; i*i <= A; i++){
      if (A % i == 0) {
        used[i]++;
        while (A%i == 0)
          A /= i;
      }
    }
    if (A > 1)
      used[A]++;
  }
  bool is_pair = true;
  bool is_not = false;
  rep(i, 1000001){
    if (used[i] > 1)
      is_pair = false;
    if (used[i] == N)
      is_not = true;
  }
  if (is_pair)
    cout << "pairwise coprime" << endl;
  else if(is_not)
    cout << "not coprime" << endl;
  else
    cout << "setwise coprime" << endl;
//  rep(i, 20)
//    cout << "val:"<<used[i] << " i:"<<i<<endl;
}
