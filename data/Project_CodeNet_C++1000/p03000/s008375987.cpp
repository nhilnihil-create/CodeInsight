#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  int a,b,c=0,d,sum=0;
  cin >> a >> b;
  rep(i,a){
    cin >> d;
    sum += d;
    if(b<sum)break;
    c++;
  }
  cout << c+1;
}