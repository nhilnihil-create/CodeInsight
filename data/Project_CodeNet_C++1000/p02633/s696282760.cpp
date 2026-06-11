#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int x;
  cin >> x;
  int ans = 1;
  int kakudo=x;
  while(kakudo%360 != 0){
    kakudo += x;
    ans++;
  }
  cout << ans << endl;
}
