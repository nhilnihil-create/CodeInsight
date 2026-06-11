//  ⚫⚫ | ⚫➖➖ ⚫⚫ ⚫➖⚫⚫ ⚫➖⚫⚫ | ➖⚫⚫⚫ ⚫ | ⚫➖ | ⚫➖⚫ ⚫ ➖⚫⚫ | ➖⚫➖⚫ ➖➖➖ ➖⚫⚫ ⚫ ⚫➖⚫
#include<bits/stdc++.h>
#define n0_nnE int main(){
using namespace std;
typedef long long ll;
n0_nnE
	ll mx=0,n,an=0;cin>>n;
	vector<ll> ls(n);
	for(ll &x:ls) cin>>x;
	for(ll x:ls){
	mx=max(mx,x);an+=mx-x;
	}
cout<<an;

}