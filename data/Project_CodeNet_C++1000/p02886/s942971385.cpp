#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 1e9+7;
const ll inf = 1e18;
const double pi = 3.1415926535897932384626;

ll mpow(ll a,ll b){
    ll res=1;
    //a%=mod;
    while(b){
    	if(b%2) res=res*a; //%mod;
		a=a*a; //%mod;
		b/=2;
	}
	return res;
}

ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return b*a/gcd(a,b);
}

void solve(){
	//code
	int n;
	cin>>n;
	int d[n];
	for(int i=0;i<n;i++)
		cin>>d[i];
		
	int count=0;	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			count+=(d[i]*d[j]);
		}
	}
	cout<<count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
 	return 0;
}
