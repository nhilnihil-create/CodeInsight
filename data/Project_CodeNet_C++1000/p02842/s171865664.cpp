#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	fastio
	int n;
	cin>>n;
	int x=ceil(n/1.08);
	if(floor(x*1.08)==n) cout<<x;
	else cout<<":(";
	return 0;
}