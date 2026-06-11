#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll yu[100010];	ll mo[100010];
int main() {
	ll n;
	cin>>n;
	n++;
	for(ll i=0;i<n;i++){
		cin>>mo[i];
	}
	for(ll i=0;i<n-1;i++){
		cin>>yu[i];
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		if(mo[i]>=yu[i]){
			ans+=yu[i];
			mo[i]-=yu[i];
		}
		else{
			ans+=mo[i];
			yu[i]-=mo[i];
			if(mo[i+1]>=yu[i]){
				ans+=yu[i];
				mo[i+1]-=yu[i];
			}
			else{
				ans+=mo[i+1];
				mo[i+1]=0;
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}