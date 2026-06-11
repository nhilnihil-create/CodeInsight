#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  int K, A, B;
  bool flag = false;
  cin >> K >> A >> B;
  repi(i, A, B+1){
    if (i % K == 0){
      flag = true;
      break;
    }
  }
  if (flag == true) cout << "OK" << endl;
  else cout << "NG" << endl;
}
