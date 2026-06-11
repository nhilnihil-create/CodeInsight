#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr char sp=' ';
constexpr ll mod=1000000007;

int k,q,d[5000];

int main(){
	cin>>k>>q;
	for(int i=0;i<k;i++){
		cin>>d[i];
	}
	while(q--){
		ll n,x,m;
		ll a=0;
		cin>>n>>x>>m;
		ll s,t;
		s=t=0;
		for(int i=0;i<k;i++){
			t+=d[i]%m;
			if(d[i]%m==0)a++;
		}
		x%=m;
		s=x+t*((n-1)/k);
		a*=(n-1)/k;
		for(int i=0;i<(n-1)%k;i++){
			s+=d[i]%m;
			if(d[i]%m==0)a++;
		}
		cout<<n-a-1-s/m<<endl;
	}
}
