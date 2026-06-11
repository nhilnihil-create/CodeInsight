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
const int MAX_N = 1000000;

bool prime[MAX_N];
VI primes;
bool isprime(int x){
  if(x < MAX_N) return prime[x];

  int sq = sqrt(x) + 1;
  for(int i=0;primes[i]<=sq;++i)
	if(x % primes[i] == 0) return false;
  return true;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  fill(prime, prime+MAX_N, true);
  for(int i=2;i<MAX_N;++i)
	if(prime[i]){
	  primes.PB(i);
	  for(int j=i+i;j<MAX_N;j+=i)
		prime[j] = false;
	}

  int N; cin >> N;
  int ans = 0;
  REP(i,N){
	int x; cin >> x;
	if(isprime(x)) ++ans;
  }
  
  cout << ans << endl;
  return 0;
}