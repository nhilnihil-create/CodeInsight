#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	long double a,b,c;
	cin >> a >> b >> c;

	long double d = (c-a-b) ;
	if(d>0 && d*d > a*b*4) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

