#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

#include <iostream>
#include <vector>
using namespace std;

//重複順列
vector<ll> buf;
void permutation(ll i, const ll size, const ll range_start, const ll range_end)
{
    if (i == size) {
      // ここで所望の作業を行う
      for(ll itr:buf){
        cout << itr;
      }
    }
    else{
        for(ll j = range_start; j <= range_end; ++j){
            buf[i] = j;
            permutation(i + 1, size, range_start, range_end);
        }
    }
}

int main(void)
{
  ll n, k, ans = 0;
  cin >> n >> k;
  vector<ll> UP(n+1),DOWN(n+1);
  ll mod = pow(10,9) +7;
  UP[0] = 0;
  DOWN[0] = n;
  FOR(i,1,n+1){
    UP[i] = UP[i-1]+i;
    DOWN[i] = DOWN[i-1]+(n-i);
  }
  FOR(i,k-1,n+1){
    ans = (ans + DOWN[i]-UP[i]+1) % mod;
  }
  cout << ans << endl;
}
