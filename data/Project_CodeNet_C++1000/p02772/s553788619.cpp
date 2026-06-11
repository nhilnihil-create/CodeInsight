#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	bool ch=true;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		if(now%2==0){
			if(now%3!=0&&now%5!=0){
				ch=false;
			}
		}
	}
	if(ch){
		cout << "APPROVED";
	}
	else{
		cout << "DENIED";
	}
	// your code goes here
	return 0;
}