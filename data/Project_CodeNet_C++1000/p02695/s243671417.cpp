#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
  ll n, m, q; cin >> n >> m >> q;
  
  
  vvll per (100000,vll(10));
  ll num = 0;
  rep(i1, 1, m+1){
    rep(i2, i1, m+1){
      rep(i3, i2, m+1){
        rep(i4, i3, m+1){
          rep(i5, i4, m+1){
            rep(i6, i5, m+1){
              rep(i7, i6, m+1){
                rep(i8, i7, m+1){
                  rep(i9, i8, m+1){
                    rep(i10, i9, m+1){
                      per[num][0] = i1;
                      per[num][1] = i2;
                      per[num][2] = i3;
                      per[num][3] = i4;
                      per[num][4] = i5;
                      per[num][5] = i6;
                      per[num][6] = i7;
                      per[num][7] = i8;
                      per[num][8] = i9;
                      per[num][9] = i10;
                      num++;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  
  vvll query (q,vll(4));
  rep(i, 0, q){
    cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];
  }
  
  ll ans = 0;
  rep(i, 1, num+1){
    ll score = 0;
    rep(j, 0, q){
      if(per[i][query[j][1]-1] - per[i][query[j][0]-1] == query[j][2]){
        score += query[j][3];
      }
    }
    ans = max(ans, score);
  }
  cout << ans << endl;
}
      
