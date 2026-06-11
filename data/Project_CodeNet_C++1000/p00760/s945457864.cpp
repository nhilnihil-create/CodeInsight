//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int tab[11];
int calc(int y, int m, int d){
  int ret = 0;
  ret = (y-1) / 3 * (tab[10]*2+20*10);
  ret += (y+2) % 3 * tab[10];
  if(y % 3 == 0)
	ret += (m-1)*20 + d-1;
  else
	ret += tab[m-1] + d-1;
  return ret;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  for(int i=1;i<=10;++i) tab[i] = tab[i-1] + ((i&1)? 20: 19);
  int N; cin >> N;
  REP(i,N){
	int y, m, d; cin >> y >> m >> d;
	cout << calc(999,10,20) - calc(y,m,d) + 1 << endl;
  }
  return 0;
}