#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

// off: この場所で繰り上がって「いない」ときの，枚数の最小値
// on: この場所で繰り上がって「いる」ときの，枚数の最小値
int off[1000020];
int on[1000020];
	
int main(){
	on[0] = 1;
	string s; cin >> s;
	int sz = s.size();
	for( int i = 0; i < sz; ++i ){
		int d = s[i]-'0';
		off[i+1] = min( off[i]+d, on[i]+(10-d) );
		on[i+1] = min( off[i]+d+1, on[i]+(10-d)-1 );
	}
	cout << off[sz] << endl;
}