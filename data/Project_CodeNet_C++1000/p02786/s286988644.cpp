#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll cnt=0;
	ll now=1;
	while(n!=0){
		n/=2;
		cnt+=now;
		now*=2;
	}
	cout <<cnt;
}