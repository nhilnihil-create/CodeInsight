#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define N 100009
#define LL long long
#define INF 0x7fffffff
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	LL s;
	cin >> s;
	LL n = sqrt(s);
	if (n * n == s) {
		cout << 0 << " " 
			<< 0 << " " 
			<< n << " " 
			<< 0 << " " 
			<< 0 << " " 
			<< n;
	}
	else {
		n++;
		LL cha = n * n - s;
		if (cha > n) {
			cout << 0 << " " << 0 << " " << 1 << " " << n - 1 << " " << n << " " << cha - n;
		}
		else {
			cout << 0 << " " << 0 << " " << 1 << " " << n << " " << n << " " << cha;
		}
	}
	return 0;
}