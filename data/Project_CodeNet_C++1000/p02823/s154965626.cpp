#include <iostream>
using namespace std;

#define ll long long

void oddSolve(ll smaller, ll bigger, ll n){
	ll a = n - smaller;
	ll b = bigger - 1; 
	ll diff = bigger - smaller; 
	ll s = (diff - 1) / 2;

	if(a <= b) cout << a - s << endl;
	else cout << b - s << endl; 
}


void solve(ll n, ll a, ll b){
	ll bigger = a, smaller = b;
	if(b > a){
		smaller = a;
		bigger = b; 
	}

	ll diff = bigger - smaller; 
	if(diff % 2 == 0){
		cout << diff / 2 << endl; 
	}
	else{
		oddSolve(smaller, bigger, n);
	}
}

int main(){
	ll n, a, b;
	cin >> n >> a >> b;

	solve(n , a , b);
}