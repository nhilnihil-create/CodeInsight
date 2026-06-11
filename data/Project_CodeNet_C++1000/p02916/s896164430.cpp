#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950


int main () {
  int n ;
  cin >> n;
  vector<int> a (n);
  vector<int> b (n);
  vector<int> c (n - 1);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  rep(i,n - 1){
    cin >> c[i];
  }
  int ans = 0;
  rep(i, n){
    ans += b[i] ;
  }
  rep(i, n){
    if(i != 0){
    if(a[i] == a[i-1] + 1){
      ans += c[a[i] - 2];
    } 
    }
  }
  cout << ans << endl;
}