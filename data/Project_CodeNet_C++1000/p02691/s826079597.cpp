#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const double PI=acos(-1.0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n);
	map<int,ll> cnt;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]+i]++;
	}
	ll ans=0;
	for(int i=0;i<n;i++) ans+=cnt[i-a[i]];
	cout<<ans;
}
