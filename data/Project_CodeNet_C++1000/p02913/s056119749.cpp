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

string s;
vector<int> z;

void init(){
	z.resize(s.size());
	z[0] = s.size();
	int i = 1, j = 0;
	while (i < s.size()) {
		while (i + j < s.size() && s[i+j] == s[j]) j++;
		z[i] = j;
		if (j == 0) { i++; continue; }
		int k = 1;
		while (i + k < s.size() && k + z[k] < j) z[i+k] = z[k], k++;
		i += k; j -= k;
	}
}

int main(){
	int n;
	string t;
	cin >> n >> t;
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		s = t[i] + s;
		init();
		for(int j = 0; j < s.size(); j++){
			ans = max(ans,min(j,z[j]));
		}
	}
	cout << ans << endl;
	return 0;
}