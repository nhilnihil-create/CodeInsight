#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n;
	cin >> n;
	vector <int> x(n),y(n);
	for(int i = 0;i < n;++i){
		cin >> x[i] >> y[i];
	}
	vector <lli> plus(n),minus(n);
	for(int i = 0;i < n;++i){
		plus[i] = x[i] + y[i];
		minus[i] = x[i] - y[i];
	}
	sort(plus.begin(),plus.end());
	sort(minus.begin(),minus.end());
	cout << max({plus[n - 1] - plus[0],plus[0] - plus[n - 1],minus[0] - minus[n - 1],minus[n - 1] - minus[0]}) << newl;

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
