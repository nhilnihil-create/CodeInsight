#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_set<ll> st;

ll gcd(ll a,ll b){
	if(b>a)
		swap(a,b);
	if(b==0) return a;
	return gcd(a%b,b);	
}

bool findprime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			if(st.find(i)!=st.end()){
				return false;
			}
			while(n%i==0){
				n/=i;
			}
			st.insert(i);
		}
	}
	if(n>1){
		if(st.find(n)!=st.end()){
			return false;
		}
		st.insert(n);
	}
	return true;
}

int main(){
 ll n;
 cin>>n;
 vector<ll> v(n);
 for(ll i=0;i<n;i++) cin>>v[i];
 int state=0;
 for(ll i=0;i<n;i++){
 	ll p=v[i];
 	if(!findprime(p)){
		state++;break;
	}
 }
 if(state==0){
 	cout<<"pairwise coprime"<<endl;
 }
 else{
 	ll g=gcd(v[0],v[1]);
 	for(ll i=2;i<n;i++)
 		g=gcd(g,v[i]);
 	if(g==1){
 		cout<<"setwise coprime"<<endl;	
	}	
	else{
		cout<<"not coprime"<<endl;
	}
 }
 
 return 0;
}

