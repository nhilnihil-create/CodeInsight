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
	int n,k,s; cin >> n >> k >> s;
	vector<int> a;
	for(int i = 0; i < k; ++i)
		a.push_back(s);
	while(a.size() < n){
		int t = s+10;
		t = t % MOD;
		a.push_back(t);
	}	
	for(int i = 0; i < n; ++i)
		cout << a[i] << gap;
	cout << "\n";
	return 0;
}