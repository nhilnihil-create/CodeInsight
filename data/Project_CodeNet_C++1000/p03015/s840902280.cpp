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

struct edge { int to, cost; };
 
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

ll dp[100010][2];

int main(){
	string l;
	cin >> l;
	dp[0][0] = 1;
	for(int i = 1; i <= l.size(); i++){
		if(l[i-1] == '1'){
			dp[i][0] = (dp[i-1][0]*2)%MOD;
			dp[i][1] = (dp[i-1][0]+dp[i-1][1]*3)%MOD;
		}else{
			dp[i][0] = (dp[i-1][0])%MOD;
			dp[i][1] = (dp[i-1][1]*3)%MOD;
		}
	}
	cout << (dp[l.size()][0]+dp[l.size()][1])%MOD << endl;
	return 0;
}