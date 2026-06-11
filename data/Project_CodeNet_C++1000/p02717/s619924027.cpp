#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main(){
	cin >> a >> b >> c;
	int t;
	t = a;
	a = b;
	b = t;
	
	t = a;
	a = c;
	c = t;
	
	printf("%d %d %d ",a,b,c);
	return 0;
}