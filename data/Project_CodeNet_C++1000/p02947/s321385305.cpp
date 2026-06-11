#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() 
{
  ll n;
  ll ans = 0;
  cin >> n;
  vector<string> s(n);
  map<string, ll> m;
  rep(i,n){
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    m[s[i]] += 1;
  }

  rep(i,n){
    if(m[s[i]] >=2){
      ans += m[s[i]] * (m[s[i]] - 1) / 2;
      m[s[i]] = 1;
    }
  }

  cout << ans << endl;
  return 0;
}
