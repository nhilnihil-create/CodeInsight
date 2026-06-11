#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ii pair<int,int>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 1e5+10;
const int mod = 1e9+7;

int n,k=0;
vi g[maxn];
int c[maxn];
map<ii,int> mp;

ii dale(ii x){
	return ii(max(x.ff,x.ss),min(x.ff,x.ss));
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	vii e(n);
	for(int i=1;i<n;++i){
		cin>>e[i].ff>>e[i].ss;
		e[i]=dale(e[i]);
		mp[e[i]]=i;
		g[e[i].ff].pb(e[i].ss);
		g[e[i].ss].pb(e[i].ff);
	}
	queue<int> q;
	q.push(1);
	vector<bool> vis(n+1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		set<int> st;
		vis[x]=true;
		for(auto &w:g[x]){
			if(!vis[w]){
				q.push(w);
			}
			int pos=mp[dale(ii(x,w))];
			//cout<<"x="<<x<<" w="<<w<<" pos="<<pos<<" c[pos]="<<c[pos]<<endl;
			if(c[pos]!=0)
				st.insert(c[pos]);
		}
		int color=1;
		for(auto &w:g[x]){
			ii aux=ii(x,w);
			int pos=mp[dale(aux)];
			if(c[pos])continue;
			while(st.count(color)) ++color;
			c[pos]=color;
			st.insert(color);
		}
		k=max(k,color);
	}
	cout<<k<<endl;
	for(int i=1;i<n;++i){
		cout<<c[i]<<endl;
	}
	return 0;
}
