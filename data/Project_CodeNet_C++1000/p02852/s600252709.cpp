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



int n, m;
string s;
void solve(){
	cin >> n >> m;
	cin >> s;
	
	vector<int> ans;
	for(int i = n; i > 0;){
		bool ok = 0;
		for(int j = min(m,i); j > 0; j--){
			if(s[i-j] == '1') continue;
			ans.push_back(j);
			i -= j;
			ok = 1;
			break;
		}
		if(!ok){
			cout << -1 << endl;
			return;
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto i = ans.begin(); i != ans.end(); i++){
		cout << *i << " ";
	}
	cout << endl;
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
