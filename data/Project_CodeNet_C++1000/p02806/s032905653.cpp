#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, t[101];
string s[101], x;
void solve(){
	cin >> n;
	i64 cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> s[i] >> t[i];
		cnt += t[i];
	}
	cin >> x;
	
	i64 ans = 0;
	for(int i = 0; i < n; i++){
		ans += t[i];
		if(s[i] == x) break;
	}
	cout << cnt- ans << endl;
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