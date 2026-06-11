#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(ll &i:a) cin>>i;
	sort(a.begin(),a.end());
	ll ans=a[n-1];
	int t=n-2,i=t;
	while(t){
		int k=min(2,t);
		t-=k;
		ans+=k*a[i--];
	}
	cout<<ans;
}