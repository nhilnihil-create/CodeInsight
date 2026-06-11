#include <iostream>
using namespace std;
long a,b,v,w,t;
int main()
{
	cin >> a >> v >> b >> w >> t;
	if ( a < b && a+v*t >= b+w*t ) cout << "YES";
	else if ( a > b && a-v*t <= b-w*t ) cout << "YES";
	else if ( a == b ) cout << "YES";
	else cout << "NO";
} 