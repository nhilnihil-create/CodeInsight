#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<int,int> P;

int main(){
	int N,M;
	cin >> N >> M;
	vector<vector<int>> A(M);
	rep(i,N){
		int a,b;
		cin >> a >> b;
		if(a>M)continue;
		A[M-a].push_back(b);
	}

	priority_queue<int> q;
	ll ans = 0;
	for(int i=M-1; i>=0; i--){
		for(int b: A[i]){ q.push(b); }
		if(!q.empty()){ ans += q.top(); q.pop(); }
	}
	cout << ans << endl;
	
}
