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
	int h,a;
	cin>>h>>a;
	double ans=h*1.0/a;
	cout<<ceil(ans);
	return 0;
}