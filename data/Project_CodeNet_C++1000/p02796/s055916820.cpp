#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))

const int MAXN = 1e9+1;
const int MAX = 1e6 + 1;
const int MOD = 1e9;
const int INF = 1e9 + 5; 

int main(){	
	int n; cin >> n;
	int x,l;
	vector<pair<int,int>> fi(n);
	for(int i = 0; i < n; ++i){
		cin >> x >> l;
		fi[i].first = x+l;
		fi[i].second = x-l;
	}
	sort(fi.begin(), fi.end());
	int ans = 1, k = fi[0].first;
	for(int i = 1; i < n; ++i){
		if(fi[i].second >= k)
			++ans,k=fi[i].first;
	}
	cout << ans << "\n";
	return 0;
}