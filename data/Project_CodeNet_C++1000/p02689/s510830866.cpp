#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const double PI=acos(-1.0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int> h(n),isGood(n,true);
	for(int &i:h) cin>>i;
	while(m--){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(h[a]>h[b]) isGood[b]=false;
		else if (h[a]<h[b]) isGood[a]=false;
		else isGood[a]=isGood[b]=false;
	}
	int ans=0;
	for(int i:isGood) ans+=i;
	cout<<ans;
}
