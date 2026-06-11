#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  int dx[] = {0,1,0,-1};
  int dy[] = {1,0,-1,0};
  map<char,int> mp;
  mp['N'] = 0;
  mp['E'] = 1;
  mp['S'] = 2;
  mp['W'] = 3;
  
  int n;
  while(cin >> n, n) {
    bool gem[21][21] = {}; 
    REP(i,n) {
      int a,b;
      cin>>a>>b;
      gem[a][b] = 1;
    }
    int m;
    cin >> m;
    int x = 10, y = 10;
    int get = 0;
    REP(i,m) {
      char c;
      cin >> c;
      int a;
      cin >> a;
      REP(i,a) {
        x += dx[mp[c]];
        y += dy[mp[c]];
        if (gem[x][y]) {
          gem[x][y] = 0;
          get++;
        }
      }
    }
    if (get == n)
      cout << "Yes"<< endl;
    else
      cout << "No" << endl;
  }
}