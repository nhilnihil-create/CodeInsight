#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main(){
	ll n,count=0;
	cin >> n;
	ll a[n+1];
	for(ll i=1;i<=n;i++) cin >> a[i];
	vector<ll>res;
	vector<ll>b(n+1,0);
	for(ll i=n;i>=1;i--){
		ll j=2;
		ll c=0;
		while(i*j<=n){
			c+=b[i*j];
			j++;
		}
		if(c%2!=a[i]){
			b[i]=1;
			count++;
			res.push_back(i);
		}
	}
	if(count==0){
		cout << count << endl;
	}
	else{
		cout << count << endl;
		for(auto p:res){
			cout << p << " ";
		}
		cout << endl;
	}
}
