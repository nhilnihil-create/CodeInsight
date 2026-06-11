#include <bits/stdc++.h>
using namespace std;
#include <math.h> 
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=1;ll mi=ch[0];
	for(ll i=1;i<n;i++){
		if(ch[i]<=mi){
			ans++;
			mi=ch[i];
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}