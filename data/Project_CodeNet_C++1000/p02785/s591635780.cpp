#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
   cin >> a[i]; 
  }
  if(n>k){
  sort(a.begin(),a.end());
  //reverse(a.begin(),a.end());
  rep(i,k){
   a.pop_back(); 
  }
  ll sum = 0;
  rep(i,a.size()){
   sum += a[i]; 
   // cout << a[i] << endl;
  }
  cout << sum << endl;
  }
  else cout << 0 << endl;
}
