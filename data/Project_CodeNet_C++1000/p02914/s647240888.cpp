#include<algorithm>
#include<chrono>
#include<climits>
#include<numeric>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
 
struct Debug{
    int cnt = 0;
    bool on = false;
    char debug[10] = "debug";
    template<class T>
    Debug & operator<<(const T & v) {
        if(on && cnt++ == 0) cerr << "debug: ";
        if(on) cerr << v << ' ';
        return *this;
    }
    Debug & operator<<(ostream&(*pManip)(ostream&)) {
        if(on) cerr << (*pManip);
        cnt = 0;
        return *this;
    }
} debug;
#define rep(i, a, b) for(auto i = (a); i < (b); i++)
#define rrep(i, a, b) for(auto i = (a); i > (b); i--)
#define all(v) (v).begin(), (v).end()
#define print(v) {if(debug.on){for(auto x : v) debug << x; debug << endl;}}
#define printn(v, n) {if(debug.on){for(int _i = 0; _i < n; _i++) debug << *(v + _i); debug << endl;}}
 

typedef unsigned long long ull;
typedef long long ll;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;


const int MAXN = 1e5 + 20;

int n;
long long a[MAXN];

long long xor_gauss() {
	int cur = 0;
	for(long long mask = 1LL << 62; mask && cur < n; mask >>= 1) {
		for(int i = cur; i < n; i++) {
			if(mask & a[i]) {
				swap(a[i], a[cur]);
				break;
			}
		}
		if(!(mask & a[cur]))
			continue;
		for(int i = 0; i < n; i++)
			if(i != cur && (mask & a[i]))
				a[i] ^= a[cur];
		cur++;
	}
	long long res = 0;
	printn(a, n);
	for(int i = 0; i < n; i++)
		res ^= a[i];
	debug << res << endl;
	return res;
}

int main(int argc, char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(argc > 1 && !strcmp(argv[1], debug.debug)) debug.on = true;

    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    long long res = 0;
    for(int i = 0; i <= 60; i++) {
    	long long mask = 1LL << i;
    	int cnt = 0;
    	for(int j = 0; j < n; j++)
    		cnt += bool(a[j] & mask);
    	if(cnt % 2 == 1) {
    		res += mask;
    		for(int j = 0; j < n; j++) {
    			if(a[j] & mask)
    				a[j] -= mask;
    		}
    	}
    }
    debug << res << endl;
    res += xor_gauss() * 2;
    cout << res << endl;

    return 0;
}




















