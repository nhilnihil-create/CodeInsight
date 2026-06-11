#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	map<ll,ll>p;
	ll ch=false;
	for(ll i=0;i<3;i++){
		ll n;
		cin>>n;
		p[n]++;
		if(p[n]==2){
			ch=true;
		}
		if(p[n]==3){
			ch=false;
		}
	}
	if(ch){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}