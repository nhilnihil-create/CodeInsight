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
	LL s;
	LL mod = pow(10, 9);
//	cout << mod;
	cin >> s;
	if(s % mod == 0){
		cout << "0 0 0 " << mod << " " << s / mod << " 0" << endl;
		return 0;
	}
	LL a = s % mod;
	LL b = s / mod + 1;
	cout << "0 0 1 " << mod << " " << b << " " << mod - a << endl; 
	return 0;
}
