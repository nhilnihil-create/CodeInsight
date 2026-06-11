#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
 
using namespace std;

ll mpow(int x, ll p){
	if(p==0) return 1;
	ll ans = mpow(x,p/2);
	if(p%2 == 1) return (x*((ans*ans)%MOD))%MOD;
	else return (ans*ans)%MOD;
}
ll fr[1000001];
void solve(){
	int x,y; cin>>x>>y;
	int a,b;
	fr[0] = 1;

	for(int i=1; i<=1000000; i++){
		fr[i] = (fr[i-1]*i)%MOD;
	}
	b = (2*x - y)/3;
	if((2*x - y) >=0 && (2*x - y)%3 ==0){
		b = (2*x - y)/3;
	}
	else{
		cout<<0; return;
	}
	if(x - 2*b >= 0){
		a = x - 2*b;
	}
	else{
		cout<<0; return;
	}
	cout<<(fr[a+b]*((mpow(fr[a],MOD-2)*mpow(fr[b],MOD-2))%MOD))%MOD;
}


int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	
	int t =1; 
	//cin>>t;

	for(int i=1; i<=t; i++){
		solve();
		cout<<"\n";
	}
	return 0;

}