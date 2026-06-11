#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
typedef long long LL;

int n, a, b, c, d;
bool f[N], g[N], vis[N];
char ch;

int main() {
	cin>>n>>a>>b>>c>>d;
	for(int i = 1; i <= n; i++) {
		cin>>ch;
		if(ch == '.') vis[i] = 1;
	}
	f[a] = g[b] = 1;
	for(int i = a + 1; i <= c; i++)
		if(vis[i]) f[i] = max(f[i - 1], f[i - 2]);
	for(int i = b + 1; i <= d; i++)
		if(vis[i]) g[i] = max(g[i - 1], g[i - 2]);
	if(c < d) {
		cout<<((f[c] && g[d]) ? "Yes" : "No")<<endl;
		return 0;
	}
	if(!f[c] || !g[d]) {
		cout<<"No"<<endl;
		return 0;
	}
	for(int i = b; i <= d; i++)
		if(g[i] && f[i - 1] && f[i + 1]) {
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"No"<<endl;
	return 0;
}