#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,x,y;
	cin >> a >> b >> x >> y;
	
	printf("%.6f ",((double)a * b) / 2);
	cout << (((b&1^1) && (b/2==y)) && (a&1^1) && (a/2==x));
}
