#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ip pair<ll,ll>
#define ff first
#define ss second
#define MAX 100005
const ll MOD = 1000000007;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	ll n;
	cin>>n;
	ll a[n];
	ll hi = 1e18, prod = 1;
	int flag = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] == 0)
			flag = 1;
	}
 
	if(flag){
		cout<<"0\n";
		return 0;
	}
	
	for(int i=0;i<n;i++){
		if(a[i] <= hi/prod)
			prod *= a[i];
		else{
			prod = -1;
			break;
		}
	}
 
	if(prod > hi)
		prod = -1;
	cout<<prod<<endl;
}