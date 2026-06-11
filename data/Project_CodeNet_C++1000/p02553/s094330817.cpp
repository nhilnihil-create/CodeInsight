/**
 *   author: master3214
 *   created: Sep-15-2020
**/

#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,c,d;
	cin >> a >> b >> c >> d;
	long long x = max(a*c, a*d);
	long long  y = max(b*c, b*d);
	cout << max(x,y);
}
