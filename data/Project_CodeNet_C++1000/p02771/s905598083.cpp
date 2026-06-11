#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	map<ll,ll>a;
	bool ch=false;
	for(ll i=0;i<3;i++){
		ll x;
		cin>>x;
		a[x]++;
		if(a[x]==2){
			ch=true;
		}
		if(a[x]==3){
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