#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

bool check(int num,int k,vector <int> &a){
	int out = 0;
	for(int i : a){
		if(i % num == 0) out += (i / num - 1);
		else out += i / num;
	}
	return out <= k;
}

void solve(){
	int n,k;
	cin >> n >> k;
	vector <int> a(n);
	int high = -1, low = 1;
	for(int i = 0;i < n;++i) cin >> a[i], high = max(high,a[i]);
	while(low < high){
		int mid = (low + high) / 2;
		if(check(mid,k,a)) high = mid;
		else low = mid + 1;
	}
	cout << low << newl;
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
