#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int inf = 1000000000;
int main(){
	set<ll>arr;
	set<ll>::iterator it,jt;
	arr.insert(0);
	arr.insert(1);
	ll start = 2;
	while(1){
		ll curr = pow(start,5);
		it = arr.end();
		it--;
		if(curr-*it>inf) break;
		arr.insert(curr);
		start++;
	}
	ll x;
	cin>>x;
	for(jt = arr.begin(); jt!=arr.end(); jt++){
		long long a_5 = *jt;
		long long b_5 = a_5-x;
		if(b_5>=0){
			it = arr.find(b_5);
			if(it!=arr.end()){
				cout<<pow(a_5,0.2)<<" "<<pow(b_5,0.2);
				return 0;
			}
		}
		else{
			it = arr.find(b_5*-1);
			if(it!=arr.end()){
				cout<<pow(a_5,0.2)<<" "<<pow(b_5*-1,0.2)*-1;
				return 0;
			}
		}
	}
}