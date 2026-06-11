#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int keta(int x){
  for(int j = 0; ; j++){
    int a = pow(10, j);int b = pow(10, j+1);
    if(a <= x && x < b){
      return j + 1;
      break;
    }else{
      continue;
    }
  }
}

int main(){
    ll n;cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ll oo = keta(i);
        if(oo % 2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
}