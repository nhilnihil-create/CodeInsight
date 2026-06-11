#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
using namespace std;
#define _GLIBCXX_DEBUG
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vit vector<lint>::iterator
#define all(x) (x).begin(),(x).end()
#define rep(x) for(int i = 0;i < (x);i++)
#define repj(x) for(int j = 0;j < (x);j++)
#define REP(i,x) for(int (i) = 0;(i) < (x);(i)++)
#define rrep(x) for(int i = (x);i >= 0;i--)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define mod 1000000007
#define graph_set(n) struct edge{int to,int cost;} vector<edge> G((n))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define range(x,y) ((x) >= 0 && (x) < h && (y) >= 0 && (y) < w)
#define pyes cout << "Yes" << endl
#define pno cout << "No" << endl
#define fin return 0
typedef vector<long long> vi;
typedef vector<pair<long long, long long>> vp;
typedef vector<vector<long long>> vvi;
typedef pair<long long, long long> pi;
typedef long long lint;
typedef long long ll;
lint qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
lint qp(int a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
lint gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
long long INF = 1e19;

//////////////////////////////////////////////////////////////////////
int num = 32;

int main() {
	int n; cin >> n;
	vi a(n); rep(n)cin >> a[i];
	
	for (int i = 0; i < 32; i++) {
		int c1=0, c2=0;
		for (int j = 0; j < n; j++) {
			if (((a[j]>>i)&1) == 0) c1++;
			else c2++;
		}
		if (!(c2 == 0 || c1 * 2 == c2)) { pno; fin; }
	}
	pyes; fin;
}
