//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	string s;
	cin >> s;
	int n = s.size() +1;
	int rtl[n] = {}, ltr[n] = {};
	REP(i, n-1) if(s[i] == '<') ltr[i+1] = ltr[i] + 1; else ltr[i+1] = 0;
	REP(i, n-1) if(s[n-2-i] == '>') rtl[n-2-i] = rtl[n-1-i] + 1; else rtl[n-2-i] = 0;
	ll ans = 0;
	int tmp;
	REP(i, n) ans += max(ltr[i], rtl[i]);
	cout << ans << endl;
}