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

int cnt;
void insertionSort(VI& A, int n, int g){
  for(int i=g;i<n;++i){
	int v = A[i];
	int j = i - g;
	while(j >= 0 && A[j] > v){
	  A[j+g] = A[j];
	  j -= g;
	  ++cnt;
	}
	A[j+g] = v;
  }
}

void shellSort(VI& A, int n){
  cnt = 0;
  VI G;
  G.PB(1);

  while(G.back()*3+1 <= n)
	G.PB(G.back()*3+1);

  reverse(ALL(G));

  cout << SZ(G) << endl;
  cout << G[0];
  REP(i,SZ(G)-1) cout << " " << G[i+1];
  cout << endl;
  
  for(int i=0;i<SZ(G);++i)
	insertionSort(A, n, G[i]);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  VI A(n);
  REP(i,n) cin >> A[i];
  shellSort(A, n);

  cout << cnt << endl;
  REP(i,n) cout << A[i] << endl;
  
  return 0;
}