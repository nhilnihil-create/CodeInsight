#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[1010], k;
void solve(){
	cin >> n >> k;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt += a[i];
	}
	
	vector<int> v;
	for(int i = 1; i*i <= cnt; i++){
		if(cnt % i == 0){
			v.push_back(cnt/i);
			v.push_back(i);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		int cc = 0;
		priority_queue<int> q;
		for(int j = 0; j < n; j++){
			cc += a[j] % v[i];
			q.push(a[j]%v[i]);
		}
		int t = cc/v[i];
		for(int j = 0; j < t; j++){
			cc -= q.top();
			q.pop();
		}
		if(cc <= k){
			chmax(ans, v[i]);
		}
	}
	cout << ans << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
