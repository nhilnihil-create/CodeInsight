#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
  int a,b;
  cin >> a >> b;
  for(int i = 13; i <= 1000; i++){
    if((int)(i*0.08) == a && (int)(i*0.1) == b){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}