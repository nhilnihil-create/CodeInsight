#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(a);
  sort(b.begin(), b.end());
  rep(i, n){
    if (b[n-1] == a[i]) cout << b[n-2] << endl;
    else cout << b[n-1] << endl;
  }
  
  return 0;
}