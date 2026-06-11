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
    int mx = 0;
    mx = min(a, b);
    mx = min(mx, c);
    for(int i=mx; i>=1; i--){
      if(a%i==0 && b%i==0 & c%i==0){
        ans += i;
        break;
      }
    }
  }
  cout << ans << endl;
}
