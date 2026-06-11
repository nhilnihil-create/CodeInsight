#include <bits/stdc++.h>
using namespace std;

int main() {
    
	long long a, b;
	cin>>a>>b;
	int yy=__gcd(a,b);
	cout << (a*b)/yy<<endl;
	return 0;
}
