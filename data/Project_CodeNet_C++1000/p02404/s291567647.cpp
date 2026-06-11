#include <cstdio>
#include <iostream>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int a, b;

int main() {
	while(1) {
		cin >> a >> b;
		if(a == 0 &&  b == 0) break;
		rep(i,a) {
			rep(j,b) {
				if(i == 0 || i == a - 1) cout << "#";
				else {
					if(j == 0 || j == b - 1) cout << "#";
					else cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}