#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>p,q,a;
	for(ll i=0;i<n;i++){
		a.push_back(i+1);
	}	
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		p.push_back(x);
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		q.push_back(x);
	}
	ll A=0;
	ll B=0;
	ll j=0;
	do{
		for(ll i=0;i<n;i++){
			if(a[i]!=p[i]){
				break;
			}
			if(i==n-1){
				A=j;
			}
		}
		for(ll i=0;i<n;i++){
			if(a[i]!=q[i]){
				break;
			}
			if(i==n-1){
				B=j;
			}
		}		
		j++;
	}while(next_permutation(a.begin(),a.end()));
	cout << abs(A-B);
	// your code goes here
	return 0;
}