#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  int s = 0;
  rep(i,n) s ^= a[i];
  vi b(n);
  rep(i,n){
    b[i] = a[i] ^ s;
    cout << b[i] << " "; 
  }
}
