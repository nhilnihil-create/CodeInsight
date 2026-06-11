#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n";

typedef pair<int, int> P;
typedef pair<string, int> Psi;




int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m;cin>>n>>m;

	vector<int> jobs[m];

	for(int i=0; i<n; i++){
		int a, b;cin>>a>>b;
		if(a >m )continue;

		jobs[m-a].push_back(b);

	}
	priority_queue<int> q;
	ll ans=0;
	for(int i=m-1; i>=0; i--){
		for(int b : jobs[i]){
			q.push(b);
		}
		if(!q.empty()){
			ans +=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;




}


