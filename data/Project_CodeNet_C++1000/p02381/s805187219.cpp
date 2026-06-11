#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

double s[1000];
int main() {
	int n; 
	while (cin >> n, n) {
		double sum = 0;
		rep(i, n) {
			cin >> s[i];
			sum += s[i];
		}
		sum /= n;
		double d = 0;
		rep(i, n) {
			d += (s[i] - sum)*(s[i] - sum);
		}
		printf("%.7lf\n", sqrt(d / n));
	}
}