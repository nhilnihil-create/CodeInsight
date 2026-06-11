#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 1500;
const int MAX_M = 1500;

/* typedef */

typedef long long ll;
typedef map<int,int> mii;

/* global variables */

int n, m;
int his[MAX_N + 1], wis[MAX_N + 1];
mii hmap;

/* subroutines */

/* main */

int main() {
  for (;;) {
    cin >> n >> m;
    if (n == 0) break;

    his[0] = wis[0] = 0;
    int h, w;
    
    for (int i = 1; i <= n; i++) {
      cin >> h;
      his[i] = his[i - 1] + h;
    }
    for (int i = 1; i <= m; i++) {
      cin >> w;
      wis[i] = wis[i - 1] + w;
    }

    hmap.clear();
    
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < i; j++) {
	h = his[i] - his[j];
	mii::iterator mit = hmap.find(h);
	if (mit == hmap.end())
	  hmap[h] = 1;
	else
	  mit->second++;
      }

    ll count = 0;
    
    for (int i = 1; i <= m; i++)
      for (int j = 0; j < i; j++) {
	w = wis[i] - wis[j];
	mii::iterator mit = hmap.find(w);
	if (mit != hmap.end())
	  count += mit->second;
      }

    cout << count << endl;
  }

  return 0;
}