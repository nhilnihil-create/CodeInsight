#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define int long long
#define elif else if
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
signed main(){
  int n, k;
  cin >> n >> k;
  int h[n];
  rep(i, 0, n){
    cin >> h[i];
  }
  sort(h, h + n);
  rep(i, 0, k){
    h[n - 1 - i] = 0;
  }
  int sm = 0;
  rep(i, 0, n){
    sm += h[i];
  }
  cout << sm << "\n";
}
 