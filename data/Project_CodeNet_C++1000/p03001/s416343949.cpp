#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;
ll MOD = 2019;

int
main() 
{

  ll w, h, x, y;
  cin >> w >> h >> x >> y;

  double ans = (double)w * h / 2;
  if((double)w / 2 == x && (double)h / 2 == y){
    printf("%f 1\n", ans);
  } else {
    printf("%f 0\n", ans);
  }

}

