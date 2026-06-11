#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
int main() {
	ll n;
	cin>>n;
	map<ll,ll>ch;
	ll a[200010];
	for(ll i=0;i<n;i++){
		cin>>a[i];
		ch[-1*a[i]]++;
	}
	for(ll i=0;i<n;i++){
		auto itr=ch.begin();
		if(a[i]*-1==itr->first){
			if(itr->second==1){
				itr++;
			}
		}
		cout <<abs(itr->first)<<endl;
	}
	// your code goes here
	return 0;
}