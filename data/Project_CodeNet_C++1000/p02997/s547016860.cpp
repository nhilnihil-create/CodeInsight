#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, k;
bool b[111][111];
void solve(){
	cin >> n >> k;
	k -= (n-1)*(n-2)/2;
	
	if(k > 0){
		cout << -1 << endl;
		return;
	}
	
	vector<int> v[111];
	vector<P> ans;
	for(int i = 2; i <= n; i++){
		//cout << 1 << " " << i << endl;
		ans.push_back({1,i});
		v[1].push_back(i);
		v[i].push_back(1);
		b[1][i] = b[i][1] = 1;
	}
	if(k != 0){
		for(int i = 2; i < n; i++){
			for(int j = i+1; j <= n; j++){
				if(b[i][j]) continue;
				b[i][j] = 1;
				k++;
				//cout << i << " " << j << endl;
				ans.push_back({i,j});
				if(k == 0) break;
			}
			if(k==0) break;
		}
	}
	cout << ans.size() << endl;
	for(auto i:ans){
		cout << i.first << " " << i.second << endl;
	}
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