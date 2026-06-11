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
	int n,k;
	cin>>n>>k;
	int sum=0;
	while(k--){
		int a;
		cin>>a;
		sum+=a;
	}
	if(sum<n) cout<<"No";
	else cout<<"Yes";
	return 0;
}