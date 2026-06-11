#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll a,b,k;
	cin >> a >> b >> k;
	if(k > a){
		ll nokori = k-a;
		a = 0;
		b -= nokori;
	}
	else{
		a -= k;
	}
	if(b < 0) b = 0;
	cout << a << " " << b << endl;
}