#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	string s; cin >> s;
	int n = s.l_ength();
	if( s[n-1] == 's' ){
		cout << s << "es" << endl;
	} else {
		cout << s << "s" << endl;
	}
}