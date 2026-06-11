#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct edge { int to; int cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};


int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n),f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];

	sort(all(a));
	sort(all(f)); reverse(all(f));

	ll l = 0, r = 1e12,m;
	while(l <= r){
		m = (l+r)/2;
		bool flag = true;
		ll tmp = k;
		for(int i = 0; i < n; i++){
			if(a[i]*f[i] > m){
				//ll num = (a[i]*f[i]-m-1)/a[i]+1;
				ll num = a[i]-m/f[i];
				tmp -= num;
				if(tmp < 0) flag = false;
			}
		}
		if(flag){
			r = m-1;
			//cout << "r" << endl;
		}else{
			l = m+1;
			//cout << "l" << endl;
		}
	}

	cout << l << endl;

	return 0;
}