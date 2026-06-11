#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int x,sum = 0,ans = 0;
  cin >> x;
  while(true){
    sum += x;
    ans++;
    if(sum%360 == 0){
      cout << ans << endl;
      return 0;
    }
  }
}