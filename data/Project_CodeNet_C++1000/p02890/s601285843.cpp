#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,x;
	cin>>n;
	ll sz[n+5], ssz[n+5];
	fill_n(sz,n+5,0);
	fill_n(ssz,n+5,0);
	for(int i=0; i<n; i++){
		cin>>x;
		sz[--x]++;
	}
	ll mx=-1,sm=0;
	for(int i=0; i<n; i++){
		if(sz[i]>0) ssz[sz[i]]++;
		sm+=sz[i];
		if(mx<sz[i]) mx=sz[i];
	}
	for(int i=1; i<=n; i++){
		int o=n/i;
		while(mx>sm/i){
			ssz[mx-1]+=ssz[mx];
			sm-=ssz[mx];
			ssz[mx]=0;
			mx--;
		}
		if(sm>mx || i==1) cout<<sm/i<<endl;
		else cout<<0<<endl;
	}
}
