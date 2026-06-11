#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int A,B,m;
string s;
int x,y,c;

void solve(){
  cin >> A >> B >> m;
  vector<int>a(A);
  vector<int>b(B);
  for(int i=0;i<A;i++)cin >> a[i];
  for(int i=0;i<B;i++)cin >> b[i];
  int ans= *min_element(a.begin(),a.end())+ *min_element(b.begin(),b.end());
  for(int i=0;i<m;i++){
    cin >> x >> y >> c;
    x--;y--;
    ans=min(ans,a[x]+b[y]-c);
  }
  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
