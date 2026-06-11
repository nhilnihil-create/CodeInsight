#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Fr = 0;
template<class T>inline void Read(T &x) {
	x = Fr = 0;
	T f = 1;
	char p = getchar();
	for(; !isdigit(p); p = getchar()) {
		if(p == EOF)
			return;
		if(p == '-')
			f = -1;
	}
	for(; isdigit(p); p = getchar())
		x = x * 10 + (p - 48);
	x *= f, Fr = 1;
}
/*================Header Template==============*/
const int maxn = 2e5 + 5;
int n;
string s;
int main() {
	ios :: sync_with_stdio(false);
	cin >> s;
	n = s.length();
	int cnt = 0;
	string pre = "";
	for(int i = 0; i < n; ++ i) {
		++ cnt;
		string now = "";
		now += s[i];
		if(pre == now)
			++ i, now += s[i];
		if(i == n) {
			-- cnt;
			break;
		}
		pre = now; 
	}
	cout << cnt << endl;
	
}