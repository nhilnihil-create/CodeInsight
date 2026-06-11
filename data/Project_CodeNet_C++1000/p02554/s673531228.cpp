#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=1e6+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

int mul(int a,int b){
	return 1ll*a*b%mod;
}

int poww(int a,int b){
	int r=1;
	while(b){
		if(b&1) r=mul(r,a);
		a=mul(a,a);
		b>>=1;
	}
	return r;
}

void add_self(int& a,int b){
	a+=b;
	if(b>0){
		if(a>=mod) a-=mod;
	}
	else{	
		if(a<0) a+=mod;
	}
}
 

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int ans=poww(10,n);
	//~ remove list dont have 0
	add_self(ans,-1*poww(9,n));
	//~ remove list dont have 9
	add_self(ans,-1*poww(9,n));
	//~ add list dont have both 0 9
	add_self(ans,poww(8,n));
	cout<<ans;
	return 0;
}
