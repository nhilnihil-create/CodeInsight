#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repin(Array,n) for(int i=0;i<n;i++){cin>>Array[i];}
using namespace std;

using ll = long long;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;
using Graph = vector<vector<int>>;

int main() {

	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N/2; i++) {
		int j = N - i;
		if (i != j)
			ans++;
	}

	cout << ans << endl;

	return 0;
}