#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n;
	bool flag = false;
	int cnt = 0;
	while( n-- ){
		int x, y; cin >> x >> y;
		if( x == y ) ++cnt;
		else cnt = 0;
		if( cnt == 3 ) flag = true; 
	}
	if( flag ) cout << "Yes" << endl;
	else cout << "No" << endl;
}