#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef std::vector<vector<int> > vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
#define debugone(x) cerr << #x << " " << x << "\n"; cerr.flush();
#define debugtwo(x) cerr << #x << "-------------" << "\n";for(auto &it: x) cerr << it << " ";cerr << "\n"; cerr.flush();
#define debugthree(x_, i_, j_) cerr << #x_ << "------------" << "\n";cerr << "from " << i_ << " to " << j_ << "\n";for(ll k_=i_; k_<=j_; k_++) cerr << x_[k_] << " ";cerr << "\n"; cerr.flush();
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const int MAX_LOG = 21;
const int MAX_N = 12800;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a == c ? 0 : 1) << endl;
}	