#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100100;

int main() {
  int x;
  cin >> x;
  vector<bool> a(100100, true);
  for(int i=2; i*i<=MAX; ++i){
    if(!a[i]) continue;
    for(int j=i+i; j<=MAX; j+=i){
      a[j] = false;
    }
  }
  for(int i=x; i<=MAX; ++i){
    if(a[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}