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
#define INF 0x3f3f3f3f
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	LL n;
	cin >> n;
	LL sqrn = sqrt(n), a, b;
	for(int i = 1; i <= sqrn; i++){
		if(n % i == 0){
			a = i;
		}
	}
	b = n / a;
	cout << a + b - 2 << endl;
	return 0;
}
