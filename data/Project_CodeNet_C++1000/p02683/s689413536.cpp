#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n,m,x;
	cin >> n >> m >> x;
	vector <int> c(n);
	vvint a(n,vector <int>(m));
	for(int i = 0;i < n;++i){
		cin >> c[i];
		for(int j = 0;j < m;++j) cin >> a[i][j];
	}
	int minn = 2e9;
	bool flag = 0;
	for(int i = 0;i < (1 << n);++i){
		int num = i;
		int curr = 0;
		int k = 0;
		vector <int> d(m);
		while(num > 0){
			if(num & 1){
				curr += c[k];
				for(int j = 0;j < m;++j){
					d[j] += a[k][j];
				}
			}
			num >>= 1;
			++k;
		}
		bool flag0 = 1;
		for(int i = 0;i < m;++i){
			if(d[i] < x){
				flag0 = 0;
				break;
			}
		}
		if(flag0){
			flag = 1;
			minn = min(minn,curr);
		}
	}
	if(flag) cout << minn << newl;
	else cout << -1 << newl;

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
