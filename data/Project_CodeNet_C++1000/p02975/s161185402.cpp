#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	ll a[n],x=0;

	rep(i,n){
		cin>>a[i];
		x^=a[i];
	}
	
	if(x==0) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
}