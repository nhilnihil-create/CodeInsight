#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62

int main() {
	ll n;
	cin>>n;
	ll ch[100010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll x2=0;
	for(ll i=0;i<n;i++){
		ll now=n-i-1;
		if(i%2==0){
			x2+=ch[now];
		}
		else{
			x2-=ch[now];
		}
	}
	cout <<x2<<endl;x2/=2;
	for(ll i=0;i<n-1;i++){
		cout << (ch[i]-x2)*2<<endl;
		x2=(ch[i]-x2);
	}
	return 0;
}