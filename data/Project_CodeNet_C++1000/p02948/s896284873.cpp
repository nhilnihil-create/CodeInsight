#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
vector<int> g[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		int a, b; cin>>a>>b;
		if(a > m)continue;
		g[m - a + 1].push_back(b);
	}
	priority_queue<int> pq;
	int ans = 0;
	for(int i = m; i >= 1; i--){
		for(auto x : g[i]){
			pq.push(x);
		}
		if(!pq.empty()){
			int x = pq.top(); pq.pop();
			ans += x;
		}
	}
	cout<<ans<<endl;
	

	return 0;
}