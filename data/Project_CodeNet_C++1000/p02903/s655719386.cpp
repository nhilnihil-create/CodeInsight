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



int n,m,a,b;
int ans[1010][1010];
void solve(){
	cin >> n >> m >> a >> b;
	
	int cnt[1010] = {};
	for(int i = 0; i < n; i++){
		int aa = a;
		bool ok = (cnt[0] < b);
		for(int j = 0; j < m; j++){
			if(aa && ok){
				ans[i][j] = 1;
				aa--;
				cnt[j]++;
			}
			else if(aa){
				ans[i][j] = 0;
				aa--;
			}
			else if(ok){
				ans[i][j] = 0;
				cnt[j]++;
			}
			else{
				ans[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j];
		}
		cout << endl;
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
