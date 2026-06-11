#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a;
  cin >> a;
  int b[a],c[a],d[a-1],sum=0;
  rep(i,a){
    cin >> b[i];
  }
  rep(i,a){
    cin >> c[i];
  }
  rep(i,a-1){
    cin >> d[i];
  }
  rep(i,a){
    sum += c[i];
    if(b[i]==b[i-1]+1) sum += d[b[i-1]-1];
  }
  cout << sum;
}