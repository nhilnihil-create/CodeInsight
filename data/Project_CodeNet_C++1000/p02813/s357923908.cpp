#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>ch,p,q;
	for(ll i=0;i<n;i++){
		ch.push_back(i+1);
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		p.push_back(x);
	}
	for(ll j=0;j<n;j++){
		ll x;
		cin>>x;
		q.push_back(x);
	}
	ll a=0;ll b=0;ll j=0;
	do {
		j++;
		bool ch2=true;
		for(ll i=0;i<n;i++){
			if(ch[i]!=p[i]){
				ch2=false;
			}
		}
		if(ch2){
			a=j;
		}
    } while (std::next_permutation(ch.begin(), ch.end()));
    j=0;
	do {
		j++;
		bool ch2=true;
		for(ll i=0;i<n;i++){
			if(ch[i]!=q[i]){
				ch2=false;
			}
		}
		if(ch2){
			b=j;
		}
    } while (std::next_permutation(ch.begin(), ch.end()));	 
    cout << abs(a-b);
	// your code goes here
	return 0;
}