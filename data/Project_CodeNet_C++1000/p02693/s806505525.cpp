#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int k,a,b;
  cin >> k >> a >> b;
  bool c = false;
  rep(i,1000){
    if(a <= k*i && k*i <= b){
      cout << "OK" << endl;
      c = true;
      break;
    }
  }
  if(c == false){
    cout << "NG" << endl; 
  }

}
