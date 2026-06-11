//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

void generalprecalculation() {

}
void solve() {
	int n;cin >> n;
	vector<int> a(n),b(n);
	priority_queue<pi> p;
	//int lock[200020]; fill(lock, lock + 200020, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		if(b[i] > a[i])p.push(mp(b[i],i));
	}

	ll ans = 0;
	while (!p.empty()) {
		pair<int,int> r = p.top();p.pop();
		int m = r.first; 
		int j = r.second;
		bool changed = false;
		if (j == 0) {
			if ((m - a[0]) % (b[n - 1] + b[1]) == 0) {
				ans += (m - a[0]) / (b[n - 1] + b[1]); m = a[0];
				changed = true;
			}
			else if (m > b[n - 1] + b[1]) {
				ans += (m - (m % (b[n - 1] + b[1]))) / (b[n - 1] + b[1]);
				m = m % (b[n - 1] + b[1]);
				changed = true;
			}
		}
		else if (j == n - 1) {
			if ((m - a[n-1]) % (b[n - 2] + b[0]) == 0) {
				ans += (m - a[n-1]) / (b[n - 2] + b[0]); m = a[n-1];
				changed = true;
			}
			else if (m > b[n - 2] + b[0]) {
				ans += (m - (m % (b[n - 2] + b[0]))) / (b[n - 2] + b[0]);
				m = m % (b[n - 2] + b[0]);
				changed = true;
			}
		}else{		
			if ((m - a[j]) % (b[j - 1] + b[j + 1]) == 0) {
				ans += (m - a[j]) / (b[j - 1] + b[j + 1]); m = a[j];
				changed = true;
			}
			else if (m > b[j - 1] + b[j + 1]) {
				ans += (m - (m % (b[j - 1] + b[j + 1]))) / (b[j - 1] + b[j + 1]);
				m = m % (b[j - 1] + b[j + 1]);
				changed = true;
			}
		}
		b[j] = m;
		if(!changed){printf("-1\n"); return;}
		if(m > a[j])p.push(mp(m,j));
		if(m < a[j]){printf("-1\n");return;}
	}
	printf("%lld\n",ans);return;
}
int main(void) {
	generalprecalculation();
	int testcase = 1;
	//cin >> testcase; //DELETE BEFORE SUBMIT
	for (int i = 0; i < testcase; i++) {
		if (testcase > 1) {
			printf("testcase #%d : ",i+1); solve();
			if (i == testcase - 1)printf("DELETE LOCAL COMMAND BEFORE SUBMIT\n");
		}
		else {
			solve();
		}
	}
	return 0;
}