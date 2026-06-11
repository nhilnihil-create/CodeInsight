#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  ll a;
  double b;
  cin >> a >> b;
  ll B = b*100+0.1;
  cout << (a*B)/100 << endl;
  return 0;
}
