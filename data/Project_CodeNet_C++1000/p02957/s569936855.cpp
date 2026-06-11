#include<bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

int main(){
	ll a,b;cin>>a>>b;
	if(a<b)swap(a,b);
	if((a-b)%2==0){
		ll p=(a+b)/2;
		cout<<p<<endl;
	}
	else cout<<"IMPOSSIBLE"<<endl;
	
	return 0;
}
