#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int x;
  cin >> x;
  for(int i=x; ;i++){
    bool ok = true;
    for(int j=2; j*j<=i; j++){
      if(i%j == 0){
        ok = false;
        break;
      }
    }
    if(ok){
      cout << i << endl;
      return 0;
    }
  }
}
