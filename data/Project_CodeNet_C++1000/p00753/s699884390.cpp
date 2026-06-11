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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  const int MAXP = 130000*2+1;
  bool prime[MAXP];
  fill(prime, prime+MAXP, true);
  prime[0] = prime[1] = false;
  for(int i=2;i<MAXP;++i)
	if(prime[i])
	  for(int j=i+i;j<MAXP;j+=i) prime[j] = false;

  int dp[MAXP];
  fill(dp, dp+MAXP, 0);
  for(int i=2;i<MAXP;++i)
	dp[i] = dp[i-1] + (prime[i]? 1: 0);
	
  while(true){
	int N; cin >> N; if(!N) break;
	cout << dp[N*2] - dp[N] << endl;
  }
  
  return 0;
}