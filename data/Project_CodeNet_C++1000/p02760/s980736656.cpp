#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

void solve(){
	int a[3][3];
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++) cin>>a[i][j];
	}
	int n; cin>>n;
	unordered_map< int, int > m;
	for(int i = 0; i<n; i++){
		int b; cin>>b;
		m[b]++;
	}

	int vis[3][3] = {};
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if(m[a[i][j]]) vis[i][j] = 1;
		}
	}
	bool ok = 0;
	for(int i = 0; i<3; i++){
		if(vis[i][0] && vis[i][1] && vis[i][2]) ok = 1;
		if(vis[0][i] && vis[1][i] && vis[2][i]) ok = 1;
	}
	if(vis[0][0] && vis[1][1] && vis[2][2]) ok = 1;
	if(vis[0][2] && vis[1][1] && vis[2][0]) ok = 1;

	if(ok) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
