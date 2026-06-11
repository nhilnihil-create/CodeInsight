/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

int n; // length of s.
int cnt2[1000005];// size of 2 in x!

int func(int i){
  return cnt2[n - 1] == ((cnt2[i] + cnt2[n - 1 - i]));
}

void precalc(){
  for (size_t i = 0; i < 1000001; i++)
  {
    if(i == 0)cnt2[i] = 0;
    else{
      int x = i;
      int add = 0;
      while (x % 2 == 0)
      {
        add++;
        x /= 2;
      }
      cnt2[i] = cnt2[i-1] + add; 
    }
  }
}

int main(int argc, char const *argv[])
{
  precalc();

  cin >> n;
  string s;cin >> s;
  vector<int> a(n);

  bool ex_1 = false;

  for (size_t i = 0; i < n; i++)
  {
    a[i] = s[i] - '0';
    a[i]--;
    ex_1 |= (a[i] == 1);
  }

  int ans_eq_1 = 0;
  for (size_t i = 0; i < n; i++)
  {
    if(a[i] == 1){
      ans_eq_1 ^= func(i);
    }
  }
  if(ans_eq_1){
    cout << 1 << '\n';
    return 0;
  }else{
    if(ex_1){
      cout << 0 << '\n';
      return 0;
    }else{
      for (size_t i = 0; i < n; i++)
      {
        a[i] /= 2;
      }

      ans_eq_1 = 0;
      for (size_t i = 0; i < n; i++)
      {
        if(a[i] == 1){
          ans_eq_1 ^= func(i);
        }
      }
      cout << ans_eq_1 * 2 << '\n'; 
    }
  }  

  return 0;
}
