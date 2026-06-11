#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int k;
  cin >> k;
  int ans = 0;
  for(int a=1; a<=k; a++)for(int b=1; b<=k; b++)for(int c=1; c<=k; c++){
    ans += gcd(a, gcd(b, c));
  }
  cout << ans << endl;
}
