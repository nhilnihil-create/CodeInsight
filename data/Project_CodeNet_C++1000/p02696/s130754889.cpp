#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	ll a,b,n; cin>>a>>b>>n;
	ll mx=0;
  if(a>n){
		for(ll i=n; i>0; i-=1){
		mx=max(mx,(a*i)/b-a*(i/b));
	}
  }else{
    	for(ll i=n; i>0; i-=a){
		mx=max(mx,(a*i)/b-a*(i/b));
	}
  }
	cout<<mx<<endl;
}