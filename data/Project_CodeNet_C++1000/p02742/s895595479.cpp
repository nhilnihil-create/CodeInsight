#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define ll long long int
#define MOD ((int)(1e9) + 7)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 ll h, w;
 cin >> h >> w;
 if(h == 1 || w == 1) cout << "1\n";
 else
 cout << (h * (w/2)) + ((w%2) * (h+2-1)/2) << '\n';
  return 0;
}
