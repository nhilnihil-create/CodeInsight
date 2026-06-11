#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int d = a-b;
	if(d <= 0) d = 0;
	int e = c -d;
	if(e < 0) e = 0;
	cout << e << endl;
}

// cout << fixed << setprecision(15) <<  << endl;