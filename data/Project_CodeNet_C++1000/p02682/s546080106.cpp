#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	ll max_sum = 0;
	if(a >= k){
			cout<<k;
			return 0;
		}

	max_sum = a;
	k = k-a;
	if(b >= k){
		cout<<max_sum;
		return 0;
	}
	k = k - b;
	cout<<max_sum - k;


}