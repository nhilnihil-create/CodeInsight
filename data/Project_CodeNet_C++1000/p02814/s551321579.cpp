#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
ll lcm(ll a,ll b){
	ll x = max(a,b);
	ll y = min(a,b);
	while(x % y != 0){
		ll t = x % y;
		x = y;
		y = t;
	}
	return a*b/y;
}

int main()
{
	ll N,M;
	cin>>N>>M;
	vector<ll> a(N);
	vector<ll> ord(N,0);
	for(ll i = 0; i < N; i++){
		cin>>a[i];
		ll k = a[i];
		while(k % 2 ==0){
			k /= 2;
			ord[i]++;
		}
		if(ord[i] != ord[0]){
			cout<<0<<endl;
			return 0;
		}
	}
	ll nLCM = 1;
	for(ll i = 0; i < N; i++){
		nLCM = lcm(nLCM,a[i]);
		if(nLCM > 2*M){
			cout<<0<<endl;
			return 0;
		}
	}
	ll halfLCM = nLCM / 2;
	cout<< (M/halfLCM) - (M/nLCM)<<endl;
	return 0;
}
