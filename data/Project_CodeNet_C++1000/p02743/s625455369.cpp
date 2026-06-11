//整数に直す方法
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll d = c-a-b;
	if(d>0 && d*d>4*a*b){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
