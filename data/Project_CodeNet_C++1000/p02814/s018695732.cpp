#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
 
using namespace std;

ll A[100001];

int f(ll x){
	for(int i=30; i>=0; i--){
		if(x%(1<<i) == 0){
			return i;
		}
	}

}

void solve(){
	ll n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>A[i];
		A[i] /= 2;
	}
	for(int i=0; i<n-1; i++){
		if(f(A[i]) != f(A[i+1])){
			cout<<0;
			return;
		}
	}
	ll lcm = 1;
	for(int i=0; i<n; i++){
		lcm = (A[i]*lcm)/__gcd(A[i],lcm);
		if(lcm > m){
			cout<<0;
			return;
		}
	}
	ll r = m/lcm;
	cout<<(r+1)/2;

}


int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//cout<<fixed<<setprecision(12);
	
	int t =1; 
	//cin>>t;

	for(int i=1; i<=t; i++){
		solve();
		cout<<"\n";
	}
	return 0;

}


