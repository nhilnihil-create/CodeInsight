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
  ll n, ans = 0;
  cin >> n;
  vector<ll> A(n);
  RAP(i,n){
    cin >> A[i];
  }
  sort(A.begin(), A.end(), std::greater<ll>());
  ans += A[0];
  ll check = 0, idx = 1;
  FOR(i,2,n){
    ans += A[idx];
    if(++check==2){
      check = 0;
      idx++;
    }
  }
  cout << ans << endl;
}
