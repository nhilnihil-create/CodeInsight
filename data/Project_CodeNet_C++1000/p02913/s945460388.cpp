//解説あり
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int t[5005][5005];

int main(void) {
  string s;
  int n;
  cin >> n >> s;
  
  for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) {
    if (s[i]==s[j]) t[i][j] = 1;
  }
  
  int ans = 0;
  for(int i=1; i<n; i++) {
    int y = 0, x = i;
    while (y<n && x<n) {
      if (t[y][x]) {
        int c = 0, p = x;
        while (y<n && x<n && t[y][x] && y<p) {c++; x++;y++;}
        ans = max(ans, c);
      
      }
      x++; y++;
    }
  }
    

    cout << ans << endl;

	return 0;
}
