#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

int main() {
  int t;
  cin >> t;
  vi results;
  for (int dataset = 0 ; dataset < t ; dataset++) {
    string a, b;
    cin >> a;
    cin >> b;
    vvi len(a.length()+1, vi(b.length()+1, 0));
    for (int ia = 0 ; ia < a.length() ; ia++) {
      for (int ib = 0 ; ib < b.length() ; ib++) {
        if (a[ia] == b[ib]) {
          len[ia+1][ib+1] = len[ia][ib]+1;
        } else {
          len[ia+1][ib+1] = max(len[ia+1][ib], len[ia][ib+1]);
        }
      }
    }
    results.pb(len[a.length()][b.length()]);
  }

  for (int it = 0 ; it < t ; it++) {
    printf("%d\n", results[it]);
  }

  return 0;
}