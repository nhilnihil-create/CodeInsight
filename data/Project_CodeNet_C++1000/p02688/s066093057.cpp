#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,k){
    int d;
    cin >> d;
    rep(j,d){
      int A;
      cin >> A;
      a[A-1]++;
    }
  }
  int cnt = 0;
  rep(i,n){
    if(a[i] == 0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}