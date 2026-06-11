#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>

using namespace std;
using ll = long long;

// vector<int> contribution(int n){
//   vector<int> a(n+1, 0);
//   a[0] = 1;
//   for(int i = 1; i <= n/2; i++){
//     a[i] = a[i-1] * (n+1 - i) / i % 2;
//   }
//   for(int i = 0; i <= n/2; i++){
//     a[n-i] = a[i];
//   }
//   // for(int i = 0; i < n+1; i++) cout << a[i] << ' ';
//   // cout << endl;
//   return a;
// }

vector<int> contribution(int n){
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++){
    if(((n-1) | i) == n-1){
      a[i] = 1;
    }
  }
  return a;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ti = clock();
  // start-----------------------------------------------
  int n; cin >> n;
  string s; cin >> s;
  vector<int> c = contribution(n);
  vector<int> a(n);
  bool f = 0;
  bool ans = 0;
  for(int i = 0; i < n; i++){
    a[i] = s[i]-'1';
    if(a[i] == 1) f = true;
  }
  if(f){
    for(int i = 0; i < n; i++){
      if(a[i]%2 && c[i]) ans = !ans;
    }
    if(ans) cout << 1 << endl;
    else cout << 0 << endl;
  }
  else{
    for(int i = 0; i < n; i++){
      if(a[i] && c[i]) ans = !ans;
    }
    if(ans) cout << 2 << endl;
    else cout << 0 << endl;
  }

  // end-----------------------------------------------
  // cerr << 1.0 * (clock() - ti) / CLOCKS_PER_SEC << endl;
}
