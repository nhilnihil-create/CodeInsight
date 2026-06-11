#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,l;
	cin>>n>>l;
	ll sa=inf;
	bool ch=true;
	ll sum=0;
	for(ll i=0;i<n;i++){
		ll now=l+i;
		sum+=now;
		if(abs(now)<=sa){
			if(now<0){
				ch=false;
				sa=abs(now);
			}
			else{
				ch=true;
				sa=abs(now);
			}
		}
	}
	if(ch==false){
		sa*=-1;
	}
	sum-=sa;
	cout <<sum;
	// your code goes here
	return 0;
}