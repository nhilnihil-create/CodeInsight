#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int n, m, q;
vector<int> a,b,c,d;
int ans;

void dfs(vector<int> A){
	if(A.size() == n+1){
		int now = 0;
		rep(i, q){
			if(A.at(b.at(i)) - A.at(a.at(i)) == c.at(i)) now += d.at(i);
		}
		ans = max(ans, now);
		return;
	}

	A.push_back(A.back());

	while(A.back() <= m){
		dfs(A);
		A.back()++;
	}
}

int main(){
	cin >> n >> m >> q;
	a = b = c = d = vector<int>(q);
	rep(i, q) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);

	dfs(vector<int>(1,1));
	
	cout << ans << endl;
	return 0;
}