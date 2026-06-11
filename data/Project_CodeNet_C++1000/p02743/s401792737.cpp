// epsを付ける方法
// A<B A<B-epsとする
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	long double a,b,c;
	cin >> a >> b >> c;
	long double eps = 1.0e-14;
	if(sqrt(a)+sqrt(b)+eps<sqrt(c)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
