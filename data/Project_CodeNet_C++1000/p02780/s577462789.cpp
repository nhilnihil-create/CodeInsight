#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

long double a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long double ans = 0.0;
	long double sm = 0.0;
	for(int i=1;i<k;i++){
		sm += a[i]/2.0+0.5;
	}
	a[0] = -1.0;
	for(int i=k;i<=n;i++){
		sm -= a[i-k]/2.0;
		sm -= 0.5;
		sm += a[i]/2.0 + 0.5;
		ans = max(ans,sm);
	}
	
	cout<<fixed<<setprecision(12)<<ans;
	
	return 0;
}
