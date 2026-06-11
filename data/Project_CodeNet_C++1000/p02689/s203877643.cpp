#include<bits/stdc++.h>
using namespace std;
int n,m,h[100010],a,b,f[100010],ans;
vector<int> v[100010];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>h[i];
	for (int i=0;i<m;i++){
		cin>>a>>b;
		if (h[a]>=h[b]) f[b]=1;
		if (h[a]<=h[b]) f[a]=1;
	}
	for (int i=1;i<=n;i++) if (f[i]==0) ans++;
	cout<<ans<<endl;
	return 0;
}