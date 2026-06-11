#include <bits/stdc++.h>
#include <sstream>
#define rep2(i,x,y) for (int i = x; i < (y); ++i)
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  ll x, k, d;
  cin >> x >> k >> d; // x:現在地 k: 繰り返し回数 d:移動距離
  x = abs(x);
  ll straight = min(k, x / d);//straight:繰り返し回数と移動回数のmin
  k -= straight;//繰り返し回数からstraight回数を減らす
  x -= straight * d;//現在地からstraight回数*移動距離を減らす
  if(k % 2 == 0){//kが偶数ならxが答え
    cout << x << endl;
  }
  else{
    cout << d-x << endl;//奇数なら移動距離から現在地を引いたのが答え
  }
  return 0;
}
