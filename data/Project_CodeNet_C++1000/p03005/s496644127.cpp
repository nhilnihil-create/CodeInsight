#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n)  for(int i=0;i<(n);++i)
#define REPr(i, n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m, n) for(int i = (n);i >=(m);--i)
#define PB push_back
#define MP make_pair
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x, y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
using namespace std;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const ll MOD = 1e9+7;

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

template<class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
///////////////////////////////////////////////
/*🍈( '-'  🍈*/
int main(){
	int N,K;
	cin >> N >> K;
	if (K == 1) {
		cout << 0 << endl;
		return 0;
	}

	cout << N - K << endl;



	return 0;
}
