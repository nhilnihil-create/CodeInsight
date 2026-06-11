#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define input(x) cin>>x;


void inputArr(ll *arr, ll &n){
	for(ll i=0;i<n;++i){
		cin>>arr[i];
	}
}



int main()
{
	
	ll x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	
	ll A[a],B[b],C[c];
	// a red apples , b green and we have to eat x, y
	inputArr(A,a);
	inputArr(B,b);
	inputArr(C,c);

    sort(A,A+a,greater<ll>());sort(B,B+b,greater<ll>());sort(C,C+c,greater<ll>());
    vector<ll> farr(x+y+c);
    ll i=0;
    
    while(i< x){
    	farr[i] = A[i];
    	++i;
	}
	while(i<x+y){
		farr[i] = B[i-x];
		++i;
	}
	while(i< x+y+c){
		farr[i] = C[i-x-y];
		++i;
	}
	sort(farr.begin(),farr.end(),greater<ll>());
	i=0;
	ll ans=0;
	for(i=0;i<x+y;++i){
		ans += farr[i];
	}
    cout<<ans<<endl;
return 0;
}

