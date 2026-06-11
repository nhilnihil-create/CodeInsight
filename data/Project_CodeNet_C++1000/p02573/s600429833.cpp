/*
BY: SAFWAAN SHAIKH
PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_d
KEY IDEAS: Graphs, Connected Components
TIME COMPLEXITY: 
*/

#define r(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#include <bits/stdc++.h>
#define f first
#define endl "\n"
#define s second
#define pb push_back
#define ms(a,b) memset(a,b,sizeof(a))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
char _;

int n,m,a,b;
int ans=0;
int root[200001],sze[200001];

int find_root(int v){
	if(v==root[v]){
		return v;
	}
	return root[v] = find_root(root[v]);
}

void unite(int x,int y){
	x = find_root(x);
	y = find_root(y);
	if(x!=y){
		if(sze[x] < sze[y]) swap(x,y);
		root[y]=x;
		sze[x]+=sze[y];
	}
}

int main(){
//	freopen("problemname.in", "r", stdin);
//  freopen("problemname.out", "w", stdout);
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		sze[i]=1;root[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		unite(a,b);
	}
	for(int i=1;i<=n;i++)ans = max(ans,sze[i]);
	
	cout << ans << endl;
	return 0;
}

