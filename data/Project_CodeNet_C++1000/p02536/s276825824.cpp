#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define takeline cin.ignore();
#define iactive cout.flush();
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll ar[N];
ll root(ll i){
	while(ar[i]!=i){
		ar[i]=ar[ar[i]];
		i=ar[i];
	}
	return i;
}
void dunion(ll a,ll b){
	a=root(a); b=root(b);
	if(a==b) return;
	if(b<a) swap(a,b);
	ar[b]=a;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		ar[i]=i;
	}
	for(i=1;i<=m;i++){
		cin>>k>>l;
		dunion(k,l);
	}
	
	k=0;
	for(i=1;i<=n;i++){
		if(ar[i]==i){
			k+=1;	
		}
	}
	cout<<(k-1);
	return 0;
}