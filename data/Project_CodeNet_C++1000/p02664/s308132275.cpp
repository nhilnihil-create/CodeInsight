#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ini(a, i) memset(a, i, sizeof(a))
#define contains(i, c) ((c).find(i) != (c).end())

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define repa(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, n) for(int i = (n)-1; i >= 0; i--)

#define TRACE(x...) x
#define watch(x) TRACE(cerr << #x" = " << x << endl)
#define watch_all(x) TRACE(cerr << #x" = "; for(auto __i : x) cerr << __i << " "; cerr << endl)

//=========================

void run_test() {
	string s;
    cin >> s;
    int n = sz(s);
    rep(i, n) if(s[i] == '?') s[i] = 'D';
    cout << s << endl;
}

//=========================

ifstream infile;
clock_t start__;
void open_func();
void close_func();

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	open_func();
	//int t = 1, _t; cin >> _t; while(t <= _t) { cout << "Case #" << t++ << ": "; run_test(); }
	//int t; cin >> t; while(t--) run_test();
	run_test();
	close_func();
	return 0;	
}

void open_func() {
	//infile = ifstream("input.in"); if(infile.good()) cin.rdbuf(infile.rdbuf());
	start__ = clock();
	cerr << "---" << endl;
}

void close_func() {
	clock_t elapsed = clock()-start__;
	cerr << "---" << endl << "(time " << fixed << setprecision(2) << elapsed * (1.0/CLOCKS_PER_SEC) << "s)" << endl;	
	//if(infile.good()) infile.close();
}
