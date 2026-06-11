//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int n, m;
	cin >> n >> m;
	int d = n - 1;
	REP1(i, m){
		cout << i << " " << i + d << endl;
		//cout << i << " " << i + d << " " << d << endl;
		if(d + d - 2 == n || (d - 2) * 2 == n)d -= 3;
		else d -= 2;
	}
	//cout << ans << endl;
}