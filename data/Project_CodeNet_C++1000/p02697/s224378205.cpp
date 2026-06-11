#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll ch[200010];
int main() {
	ll n,m;
	cin>>n>>m;
	ll l=0;
	ll r=m+1;
	for(ll i=0;i<m;i++){
		if(i%2==0){
			ch[l]=m-i;
			ch[l+m-i]=m-i;
			l++;
		}
		else{
			ch[r]=m-i;
			ch[r+m-i]=m-i;
			r++;
		}
	}
	vector<ll>a[100010];
	for(ll i=0;i<n;i++){
		ll now=ch[i];
		a[now].push_back(i+1);
	}
	for(ll i=1;i<=m;i++){
		cout << a[i][0]<<" "<<a[i][1]<<endl;
	}
	// your code goes here
	return 0;
}