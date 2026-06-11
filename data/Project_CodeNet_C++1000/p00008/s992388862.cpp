#include <stdio.h>
#include <iostream>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
int n;
int main() {
	int a, b, c, d;
	while(scanf("%d\n", &n) != EOF) {
		int count = 0;
		rep(a,10) {
			rep(b,10) {
				rep(c,10) {
					rep(d,10) {
						if(a + b + c + d == n) count++;
					}
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}