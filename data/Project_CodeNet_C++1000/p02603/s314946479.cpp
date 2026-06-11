#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

typedef long long ll;

void solve(){
	ll ans=1000;
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int mn=1e9+7;
	for(int i=0;i<n;i++){
		if(mn>=a[i]){
			mn=a[i];
		}
		else{
			ans=ans%mn+(ans/mn*a[i]);
			mn=a[i];
		}
	}
	cout<<ans;
}

int main(){
	Red;
	int T=1;
	//cin>>T;
	while(T--)solve();
}