#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <utility>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define SUM(n) ((n)+1)*(n)/2
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
 
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> ans;

  int i;
  while(n > 0){
    for( i = m ; i > 0 ; i -- ){
      if( n - i >= 0 && s[n - i] == '0' ){
	ans.pu(i);
	n -= i;
	break;
      }
    }

    if(i == 0){
      cout << -1 << '\n';
      return 0;
    }
    // cout<< n << " ";
  }

  for(i = ans.size() - 1 ; i > 0 ; i -- ){
    cout << ans[i] << " ";
  }
  cout << ans[0] << '\n';
  return 0;
}
