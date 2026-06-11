#include<bits/stdc++.h>
using namespace std;
signed main(){
	int a, b,c ,d ,e;
	cin >> a >> b;
	c =a/b;
	d =a%b;
	e =100000 * d/b;
	cout << c << " " << d << " " << c << "."<< e << endl;
	return 0;
}

