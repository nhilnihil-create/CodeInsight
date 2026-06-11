#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
   cin >> a[i]; 
  }
  sort(a.begin(),a.end());
  int tairyoku = 0;
  ll minimum = 1e18;
  int place;
  rep(i,100){
    rep(j,n){
      tairyoku += (a[j]-i)*(a[j]-i);
    }
    if(tairyoku < minimum) {
      minimum = tairyoku;
      tairyoku = 0;
    }
    else tairyoku =0;
  }
  int sum =0;
  rep(i,n){
    sum += a[i];
  }
  if(sum ==0) minimum =0;
  cout << minimum << endl;
}
