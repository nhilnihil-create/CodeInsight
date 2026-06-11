#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int x,ans = 0,sum = 0;
  cin >> x;
  while(true){
    if(sum%360 == 0 && sum >= 360){
      cout << ans << endl;
      return 0;
    }
    sum += x;
    ans++;
  }
}