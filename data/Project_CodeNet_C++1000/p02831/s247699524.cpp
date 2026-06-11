#include<iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	ll ans = a*b/gcd(a,b);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a,b;
	cin >> a >> b;
	cout << lcm(a,b);
	return 0;
}