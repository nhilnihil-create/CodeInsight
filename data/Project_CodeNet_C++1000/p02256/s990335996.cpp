#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	int a, b;
	cin >> a >> b;
	if(a < b) swap(a, b);
	int m = b;
	while(m) {
		int t = a / m;
		swap(a -= t * m, m);
	}
	cout << a << endl;
	return 0;
}