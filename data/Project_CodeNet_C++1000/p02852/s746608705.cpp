#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))
 
using namespace std;
 
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-12;
const double PI = acos(-1.0);

int main() {
	int n,m;
	string s;
	cin >> n >> m >> s;

	vi p,ans;
	rep(i,s.size()) if(s[i] == '0') p.push_back(i);
	int i = n,flag = 1;
	while(i > 0){
		int d = *lower_bound(all(p),max(0,i-m));
		if(i == d) { flag = 0; break; }
		ans.push_back(i-d);
		i = d;
	}
	if(flag){
		reverse(all(ans));
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << (i!=ans.size()-1?" ":"\n");
		}
	}else{
		cout << -1 << endl;
	}
	return 0;
}