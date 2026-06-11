#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>ch;
	for(ll i=0;i<n;i++){
		ch.push_back(i+1);
	}
	ll a,b;
	vector<ll>A,B;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		A.push_back(x);
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		B.push_back(x);
	}
	ll now=0;
	do{
		if(ch==A){
			a=now;
		}
		if(ch==B){
			b=now;
		}
		now++;
	}while(next_permutation(ch.begin(),ch.end()));
	cout << abs(a-b);
	// your code goes here
	return 0;
}