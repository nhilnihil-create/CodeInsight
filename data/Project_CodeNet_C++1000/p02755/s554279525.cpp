#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int check(double a){
	int ad = a;
	if(a > ad) ad++;
	return ad;
}

int main(){
	int a, b;
	cin >> a >> b;
	double ar1 = 100.0/8.0;
	double br1 = 100.0/10.0;
	double a1 = a * ar1;
	int aa = check(a1);
	double a2 = a1 + ar1;
	int aaa = check(a2);
	double b1 = b * br1;
	int bb = check(b1);
	double b2 = b1 + br1;
	int bbb = check(b2);
	int mi = 1e8;
	for(int i = aa; i < aaa; i++){
		for(int j = bb; j < bbb; j++){
			if(i == j){
				mi = min(mi, i);
			}
		}
	}
	if(mi == 1e8) cout << -1 << endl;
	else cout << mi << endl;
}
