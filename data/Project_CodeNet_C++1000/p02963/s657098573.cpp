#include <bits/stdc++.h>
using namespace std;

int main() {
	long long s;
	cin >> s;

	//x1==0 x1<=x2<=x3 

	//s==a*b-k*(b-l) となるa,b,k,lを見つければよい　出力は0,b,k,0,a,l
	//どうやってみつけるの
	//sにわずかに大きいa*bを設定する→a*b-sについてx*yの形で因数分解、k,b-lにする。x*yは素数でも成立する
	long long a, b, k, l;
	a = ceil(sqrt(s));
	b = ceil(sqrt(s));
	long long xy = (a * b) - s;
	l = b - 1;
	k = xy;
	cout << 0 <<" "<< b <<" "<< k <<" "<< 0 << " " << a << " " << l;
}