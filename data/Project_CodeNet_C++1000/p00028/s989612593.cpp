#include <iostream>

using namespace std;
#define rep2(x,from,to) for(int x=(from); x<(to); (x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	int n, a[101];
	rep2(i,1,100) {
		a[i] = 0;
	}
	while(cin >> n) {
		a[n]++;
	}
	int max = 0;
	rep2(i,1,100) {
		if(max < a[i]) max = a[i];
	}
	rep2(i,1,100) {
		if(a[i] == max) {
			cout << i << endl;
		}
	}
	return 0;
}