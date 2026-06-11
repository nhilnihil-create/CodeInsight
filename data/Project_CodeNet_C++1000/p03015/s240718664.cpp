#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

ll on[100010];
ll off[100010];

int main(){
	string s; cin >> s;
	int n = s.size();
	on[0] = 2, off[0] = 1;
	for( int i = 0; i < n; ++i ){
		if( s[i+1] == '1' ){
			on[i+1] = on[i]*2;
			off[i+1] = on[i]+off[i]*3;
		} else {
			on[i+1] = on[i];
			off[i+1] = off[i]*3;
		}
		on[i+1] %= mod;
		off[i+1] %= mod;
	}
	cout << ( on[n-1] + off[n-1] ) % mod << endl;
}