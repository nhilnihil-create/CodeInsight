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
  ll n, ans=0;
  bool flag = true;
  string S;
  cin >> n >> S;
  RAP(i, 1000){
    ostringstream sout;
    sout << std::setfill('0') << std::setw(3) << i;
    string s = sout.str();
    flag = true;
    ll j=0;
    RAP(k, 3){
      while(S[j]!=s[k]){
        j++;
        if(j>=S.size()){
          flag = false;
          break;
        }
      }
      j++;
      if(flag==false){
        break;
      }
    }
    if(flag){
      //cout << s << endl;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
