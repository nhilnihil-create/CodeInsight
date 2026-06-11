#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	fastio
	ll n,k;
	cin>>n>>k;
	ll ar[n];
	for(int i=0;i<n;++i) cin>>ar[i];
	sort(ar,ar+n);
	ll sum=0;
	for(int i=0;i<n-k;++i) sum+=ar[i];
	cout<<sum;
	return 0;
}