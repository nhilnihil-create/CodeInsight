#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;


signed main(){
	//cout << fixed << setprecision(10);
	string s; cin >> s;
	int n = s.size();
	ll even = 0, odd = 0,memo = -1,cnt = 0;
	vl ans(n);
	rep(i,0,n){
		if(s[i] == 'R'){
			if(memo != -1){
				ans[memo] += even;
				ans[memo+1] += odd;
			}
			even = 0;
			odd = 0;
			memo = i;
			cnt = 0;
		}
		else{
			if(cnt % 2 == 0)even++;
			else odd++;
		}
		cnt++;
	}
	ans[memo] += even;
	ans[memo+1] += odd;
	even = 0;
	odd = 0;
	memo = -1;
	cnt = 0;
	for(int i = n-1; i>=0;--i){
		if(s[i] == 'L'){
			if(memo != -1){
				ans[memo] += even;
				ans[memo-1] += odd;
			}
			even = 0;
			odd = 0;
			memo = i;
			cnt = 0;
		}
		else{
			if(cnt % 2 == 0)even++;
			else odd++;
		}
		cnt++;
	}
	ans[memo] += even;
	ans[memo-1] += odd;
	rep(i,0,n)cout << ans[i] << endl;

	return 0;
}