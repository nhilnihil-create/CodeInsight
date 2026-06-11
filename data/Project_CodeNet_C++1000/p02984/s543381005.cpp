#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<ll> a(n);
	for(auto &x : a){
		cin>>x;
	}
	ll sum = accumulate(a.begin(), a.end(), 0LL);
	ll b_0 = sum;
	for(int i = 1; i < n; i += 2){
		b_0 -= 2*a[i];
	}
	vector<ll> b(n); b[0] = b_0;
	for(int i = 1; i < n; i++){
		b[i] =2*a[i - 1] - b[i - 1];
	}
	for(auto x : b){
		cout<<x<<" ";
	}

	return 0;
}