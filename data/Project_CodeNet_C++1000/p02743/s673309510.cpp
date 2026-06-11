#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll lhs = 4 * a * b;
	ll rhs = (c - a - b);
	if(rhs <= 0){
		puts("No");
		return 0;
	}
	rhs *= rhs;
	if(lhs < rhs){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}
