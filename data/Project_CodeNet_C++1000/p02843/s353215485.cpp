#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  int x;
  cin >> x;

  int zy = x / 100;
  int per = x % 100;
  int cnt = zy;
  for(int i = 5; i >= 0; i--){
    if(per == 0){
      break;
    }
    if(per % i == 0){
      cnt = per / i;
      per %= i;
    }
  }

  if(cnt != 0 && zy >= cnt){
    cout << 1 << endl;
  }else{
    cout << 0 << endl;
  }

}

