#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int cnt = 0;
  int it = 1;
  rep(i, n){
    if(a[i] != it){
      cnt++;   
    }else{
      it++;
    }
  }
  if(it != 1){
    cout << cnt << endl;
  }else{
    cout << -1 << endl;
  }
}