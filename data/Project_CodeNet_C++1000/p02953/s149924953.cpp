#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi h(n);
  rep(i,n) cin >> h[i];
  int mx = 0;
  rep(i,n){
    mx = max(mx, h[i]);
    if(mx - h[i] > 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
