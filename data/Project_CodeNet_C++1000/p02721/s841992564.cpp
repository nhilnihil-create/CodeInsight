#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, k, c;std::cin >> n >> k >> c;
  string s;std::cin >> s;

  ll now = 1;
  vll LEFT(n+2, -1), RIGHT(n+2, -1);
  for(int i=0;i<n;i++){
    if(s[i]=='x') continue;
    if(now==1||i - LEFT[now-1]>c){
      LEFT[now] = i;
      now++;
    }
  }
  now = 1;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='x') continue;
    if(now==1||RIGHT[now-1] - i>c){
      RIGHT[now] = i;
      now++;
    }
  }
  if(LEFT[k+1]!=-1){
    std::cout << '\n';
    return 0;
  }
  vll ans;
  for(int i=1;i<=k;i++){
    ll l = LEFT[i];
    ll r = RIGHT[k+1-i];
    if(l==r) ans.push_back(l);
  }
  re(i, ans.size()) std::cout << ans[i] + 1 << '\n';
  return 0;
}
