#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double
#define rep(i, x, n, j) for(int i=x;i<(int)n;i+=j)
#define F first
#define S second
#define per(i, x, n, j) for(int i=(int)n-1;i>=0;i-=j)
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()

const int N = 2000100;
const ll MOD = 1e9+7;
const ll inf = 1e18+5;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int _;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, s; cin >> n >> k >> s;
	vector<int> a;
	rep(i,0,k,1) a.push_back(s);
	rep(i,0,n-k,1){
		if(s==1e9) a.push_back(1);
		else a.push_back((int)1e9);
	}
	rep(i,0,sz(a),1) cout << a[i] << " ";
	cout << endl;
	return 0;
}
