#include <bits/stdc++.h>
using namespace std;
#define forloop(n) for(int i = 0; i < n; i++)
#define ll long long
/*ll sum(vector<ll> vec, int left, int right){
	if(right == left){
		return vec[0];
	}
	return vec[right] + sum(vec, left, right-1);
}*/
int main(){
	int n; cin>>n;
	ll res = 0, sum = 0;
	forloop(n){
		ll a,b; cin>>a>>b;
		sum += a*b;
		res += b;
	}
	cout<< (sum-1)/9 + res-1;
	return 0;
}