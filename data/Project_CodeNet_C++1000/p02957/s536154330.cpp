#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
const int MOD = 1000000007;

int main(){
  int a,b;
  cin >> a >>b;
  
  if((b-a)%2)
    cout << "IMPOSSIBLE" << endl;
  else{
    cout << a + (b-a)/2 << endl;
  }
  return 0;
}