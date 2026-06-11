#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define INF 2e9
using namespace std;
const int N=1e6+1;
const int mod=1e9+7;
ll fastexp(ll base,ll exp){
	base%=mod;
	ll ans=1;
	while(exp>0){
		if(exp&1){
			ans*=base;
			ans%=mod;
		}
		base*=base;
		base%=mod;
		exp/=2;
	}
	return ans;
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int sumofdigits(int n){
	int sum = 0;
	while(n!=0){
		sum += n%10;
		n = n/10;
	}
	return sum;
}
int arr[N];
int ar[N];
int main() {
		int n;
		cin >> n;
		if(n >= 400 && n <= 599){
			cout << 8;
		}
		else if(n>=600 && n <=799){
			cout << 7;
		}
		else if(n >= 800 && n <= 999){
			cout << 6;
		}
		else if(n >= 1000 && n <= 1199){
			cout << 5;
		}
		else if(n >= 1200 && n <= 1399){
			cout << 4;
		}
		else if(n >= 1400 && n <= 1599){
			cout << 3;
		}
		else if(n >= 1600 && n <= 1799){
			cout << 2;
		}
		else {
			cout << 1;
		}
		return 0;
}