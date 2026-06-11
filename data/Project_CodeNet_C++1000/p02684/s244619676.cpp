#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void dfs(int s,vector <int> &a,vector <bool> &vis,vector <int> &chain,int &node){
	vis[s] = 1;
	chain.push_back(s);
	if(!vis[a[s]]) dfs(a[s],a,vis,chain,node);
	else node = a[s];
	return;
}

void solve(){
	int n;
	lli k;
	cin >> n;
	cin >> k;
	vector <bool> vis(n,0);
	vector <int> a(n);
	vector <int> chain;
	for(int i = 0;i < n;++i){
		cin >> a[i];
		a[i]--;
	}
	int node = 0;
	dfs(0,a,vis,chain,node);
	int t = 0,l;
//	for(int i = 0;i < chain.size();++i) cout << chain[i] << " ";
//	cout << newl << newl;
	for(int i = 0;i < (int)chain.size();++i){
		if(chain[i] == node) break;
		else ++t;
	}
	if(k <= (lli)t) cout << chain[k] + 1 << newl;
	else{
		k = k - t;
		l = (int)chain.size() - t;
	//	cout << t << " " << l << newl;
		cout << chain[(lli)t + k % (lli)l] + 1 << newl;
	}

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
