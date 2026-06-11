#include <iostream>
using namespace std;

long long gcd(long long x, long long y){
	if(y == 0) return x;
	return (gcd(y,x%y));
}

int main(){
	long long l,r,a,b;	
	cin >> l >> r >> a >> b;
		
	long long dba = (r/a) - ((l-1)/a);
	long long dbb = (r/b) - ((l-1)/b);
	long long c = (a*b) / gcd(a,b);
	long long dbab = (r/c) - ((l-1)/c);

	cout << (r-l+1) - (dba+dbb-dbab);
}
