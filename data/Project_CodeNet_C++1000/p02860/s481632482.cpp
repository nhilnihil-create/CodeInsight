//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp; int n;
	string s;
	cin >> n >> s;
	if (s.size() % 2 == 0 
	&& s.substr(0, s.size()/2) == s.substr(s.size()/2) )cout << "Yes" << endl;
	else cout << "No" << endl;
	
	//cout << ans << endl;
}