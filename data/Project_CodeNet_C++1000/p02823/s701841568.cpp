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
  ll n, a, b;
  cin >> n >> a >> b;
  
  // 3 4
  // 2 3
  if (abs(a-b) % 2 == 0) {
    cout << abs(a-b)/2 << endl;
  } else {
    ll res = 1000000000000000000;
    res = min(res, abs(max(a, b) - 1)); //always win
    res = min(res, abs(min(a, b) - n)); //always lose
    
    // first to win, then merge if even
    ll leftPad = min(a, b)-1;
    ll wa = a-leftPad;
    ll wb = b-leftPad;
    if (abs(wa-wb) % 2 != 0) {
      // win again so range is even
      res = min(res, 1+leftPad+abs(wa-(wb-1))/2);
    } else {
      res = min(res, leftPad+abs(wa-wb)/2);
    }
    
    // first to lose, then merge if even
    ll rightPad = n-max(a, b);
    ll la = a-rightPad;
    ll lb = b-rightPad;
    if (abs(la-lb) % 2 != 0) {
      // lose again so range is even
      res = min(res, 1+rightPad+abs((la+1)-lb)/2);
    } else {
      res = min(res, rightPad+abs(la-lb)/2);
    }
    
    cout << res << endl;
  }
  return 0;
}