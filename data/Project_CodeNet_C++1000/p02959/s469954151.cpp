#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  
  vector<ll> cities;
  
  for (int i = 0; i < n+1; ++i) {
    ll c;
    cin >> c;
    
    cities.pb(c);
  }
  
  ll res = 0;
  
  for (int i = 0; i < n; ++i) {
    ll h;
    cin >> h;
    
    
    int mi0 = min(h, cities.at(i));
    h -= mi0;
    
    int mi1 = min(h, cities.at(i+1));
    
    cities.at(i) -= mi0;
    cities.at(i+1) -= mi1;
    
    res += mi0;
    res += mi1;
  }
  
  cout << res << endl;
  
  return 0;
}