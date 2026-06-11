#include <bits/stdc++.h>
using namespace std;
long long my_gcd(long long x, long long y){
	while(y!=1){
		if(x%y == 0) return y;
		long long temp = x;
		x = y;
		y = temp%y;
	}
	return 1;
}
	

int main(){
	long long a,b,c,d;
	cin >> a >> b >> c >> d;
	long long gcd = my_gcd(c,d);
	long long scm = c/gcd*d;
	//cout << gcd << " " << scm << endl;
	long long count = 0;
	count += b/c;
	count += b/d;
	count -= b/scm;
	count -= (a-1)/c;
	count -= (a-1)/d;
	count += (a-1)/scm;

	cout << (b-a+1)-count;
	
}
		
		
    
	


