#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	int cnt = 0;
	while( n > 0 ){
		n /= k;
		++cnt;
	}
	cout << cnt << endl;
}