#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 2e5+5;
ll n, q;
bool vis[nax];
unordered_map<ll, ll>val;
vector<ll>arr[nax];

void dfs(ll a, ll b){
		vis[b]=1;
		val[b]+=val[a];
		for(auto x:arr[b]){
			if(!vis[x]){
				dfs(b, x);
			}
		}
	}

int main(){
	IOS
	cin >> n >> q;
	for(int i=0;i<n-1;i++){
		ll a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	while(q--){
		ll node, nilai;
		cin >> node >> nilai;
		val[node]+=nilai;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		for(auto x:arr[i]){
			if(!vis[x]){
				dfs(i, x);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout << val[i];
		if(i!=n){
			cout << ' ';
		}
	}
	cout << '\n';
}
