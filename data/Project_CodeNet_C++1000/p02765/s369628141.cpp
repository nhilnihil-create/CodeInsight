#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	int n, r; cin >> n >> r;
	if( n >= 10 ){
		cout << r << endl;
	} else {
		cout << r+100*(10-n) << endl;
	}
}