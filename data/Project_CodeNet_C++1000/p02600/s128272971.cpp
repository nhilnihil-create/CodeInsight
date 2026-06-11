//msol2020_a.cpp
//Sun Aug  2 20:38:51 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int x;
	cin >> x;

	if (x<=599){
		cout << "8" << endl;
	}else if (x <= 799) {
		cout << "7" << endl;
	}else if (x <= 999) {
		cout << "6" << endl;
	}else if (x <= 1199) {
		cout << "5" << endl;
	}else if (x <= 1399) {
		cout << "4" << endl;
	}else if (x <= 1599) {
		cout << "3" << endl;
	}else if (x <= 1799) {
		cout << "2" << endl;
	}else if (x <= 1999) {
		cout << "1" << endl;
	}

}