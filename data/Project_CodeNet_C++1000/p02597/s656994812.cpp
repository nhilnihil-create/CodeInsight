#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
4
WWRR

RRWWにする必要がある
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, ans = 0;
  cin >> N;
  string S;
  cin >> S;
  ll i=0, j=S.size()-1;
  while (S[i]){
    if (S[i] == 'W'){
      while(S[j] == 'W' && j > i){
        j--;
      }
      if (j > i){
        swap(S[i], S[j]);
        ans++;
      }
      else
        break;
    }
    i++;
  }
  cout << ans << endl;
}
