#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define mp make_pair
#define pb push_back
void solve(){
	int n;
	cin>>n;
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	map<ll,int>m;
	ll a1[n],a2[n];
	for(int i=0;i<n;i++){
		a1[i]=a[i]+i+1;
		m[a1[i]]++;
		a2[i]=i+1-a[i];
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(m.find(a2[i])!=m.end()){
			ans+=m[a2[i]];
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
	//cin>>T;
	while(T--)
		solve();
}

