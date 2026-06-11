#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
#define rep2(i,from,to) for(int i=(from); i<(to); ++(i))
#define rep(i,to) rep2(i,0,to)
int main() {
	int n;
	while(cin >> n && n) {
		int a[5001];
		int Max = INT_MIN;
		rep(i,n) {
			cin >> a[i]; 
		}
		rep(i,n) {
			int sum = 0;
			rep2(j,i,n) {
				sum += a[j];
				Max = max(Max, sum);
			}
		}
		cout << Max << endl;
	}
	return 0;
}