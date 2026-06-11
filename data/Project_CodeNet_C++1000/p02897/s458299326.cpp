//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	
	long double ans = (n+1)/2;
	
	ans /= n;
	cout<<ans;
	
	return 0;
}
