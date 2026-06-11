#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n,K;cin>>n>>K;

	if (K > ((n - 1) * (n - 2) / 2)) cout << -1 << endl;
	else{
		vector<vector<bool>> g(n + 1,vector<bool> (n + 1,false));
		int m = 0;//頂点数
		for(int i = 2; i <= n; i++) {//1からの辺を張る
			g[1][i] = true;
			m++;
		}
		for(int i = 2; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				g[i][j] = true;
				m++;
			}
		}
		for(int i = 0; i < K; i++) {
			bool flag = true;
			for(int j = 2; j <= n; j++) {
				for(int k = j + 1; k <= n; k++) {
					if (g[j][k] && flag){
						g[j][k] = false;
						flag = false;
						m--;
					}
				}
			}
		}
		cout << m << endl;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if (g[i][j])cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}