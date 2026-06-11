#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)

int main() {
	char s[110], p[110];
	scanf("%s", s);
	scanf("%s", p);
	int n = 0;
	while(s[n] != '\0') ++n;
	int m = 0;
	while(p[m] != '\0') ++m;
	rep(i,n) {
		bool f = 1;
		rep(j,m) {
			if(s[(i + j) % n] != p[j]) {
				f = 0;
				break;
			}
		}
		if(f) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}