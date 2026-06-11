#include <iostream>
#include <string>
#include <vector>
#include <queue>
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


bool nCr_odd(ll a, ll b){
  while(a!=0&&b!=0){
    if(!(a%2)&&(b%2)) return false;
    a/=2, b/=2;
  }
  return true;
}

ll n;
int main(int argc, char const *argv[]) {
  std::cin >> n;
  vll a(n);
  bool f = false;
  string s;std::cin >> s;
  for(int i=0;i<n;i++) {
    a[i] = s[i]-'1';
    if(a[i]==1) f = true;
  }
  ll ret = 0;
  for(int i=0;i<n;i++) ret = (ret + nCr_odd(n-1, i)*a[i])%2;

  if(ret){
    std::cout << 1 << '\n';
    return 0;
  }
  if(f){
    std::cout << 0 << '\n';
    return 0;
  }
  re(i, n) a[i]/=2;
  ret = 0;
  for(int i=0;i<n;i++) ret = (ret + nCr_odd(n-1, i)*a[i])%2;
  if(ret==1){
    std::cout << 2 << '\n';
    return 0;
  }
  std::cout << 0 << '\n';
  return 0;
}
