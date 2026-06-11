#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long
#define mod 1000000007

#define COMMENT

int N, D, A, x, h;
vector<pair<ll, int> > X;
int H[1 << 20];

int main() {

 // freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);

  cin >> N >> D >> A;
  for(int i = 0;i < N;i++) {
    cin >> x >> h;
    int num_bombs = ceil(h * 1.0 / A);
    X.push_back(make_pair(x, num_bombs));
  }

  ll ans = 0;
  sort(X.begin(), X.end());
  for(int i = 0;i < N;i++) {
    if(i) H[i] += H[i-1];

    if(X[i].second + H[i] <= 0) continue;
    ans += X[i].second + H[i];
    int l = upper_bound(X.begin(), X.end(), make_pair(X[i].first + 2 * D, INT_MAX)) - X.begin() - 1;

    H[l+1] += X[i].second + H[i];
    H[i] += -(X[i].second + H[i]);
  }

  cout << ans << endl;

  return 0;
}
