#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int x;
  cin >> x;
  vector<ll> vec(250);
  rep(i,240){
    ll sum = 1;
    rep(j,5) sum *= (i - 120);
    vec.at(i) = sum;
  }
  rep(i,240)rep(j,240){
    if (x == vec.at(i) - vec.at(j)){
      printf("%d %d\n", i - 120, j - 120);
      return 0;
    }
  }
  cout << "error" << endl;
  return 0;
}
