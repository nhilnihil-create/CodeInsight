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
  vector<ll> a;
  
  cin >> n;
  
  while (n--) {
    ll k;
    cin >> k;
    a.pb(k);
  }
  
  for (int i = 0; i < a.size()-1; ++i) {
    if (i == 0) {
      a[i]--;
    } else {
      if (a[i]-1 >= a[i-1]) {
        a[i]--;
      }
      /*
      if (a[i] < a[i+1]) {
        if (a[i]-1 >= a[i-1]) {
          a[i]--;
        }
      } else if (a.at[i] == a.at[i+1]) {
        if (a[i]-1 >= a[i-1]) {
          a[i]--;
        } else {
          // not possible
          // ex: 3 2 2 -> 2 2 2 -> 2 1 2?
        }
      } else {
        if (a[i]-1 <= a[i+1]) {
          if (a[i]-1 >= a[i-1]) {
            a[i]--;
          } else {
            // not possible
            // ex: 4 3 2 -> 2 3 2 
          }
        } else {
          // not possible
          // ex: 4 2 -> 3 2?
        }
      }
      */
    }
  }
  
  bool res = true;
  
  for (int i = 0; i < a.size()-1; ++i) {
    if (a.at(i) > a.at(i+1)) {
      res = false;
    }
  }
  
  if (res) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  
  cout << endl;
  return 0;
}