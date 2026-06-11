#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n;
	cin>>n;
	for(ll i=n;;i++){
		bool ch=false;
		for(ll j=2;j<=sqrt(i);j++){
			if(i%j==0){
				ch=true;
				break;
			}
		}
		if(ch==false){
			cout << i;
			return 0;
		}
	}
	// your code goes here
	return 0;
}