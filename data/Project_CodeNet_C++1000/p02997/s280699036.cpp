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
    int n, k;
	cin >> n >> k;
	if (k > (n-1)*(n-2) / 2) cout << -1 << endl;
	else{
		ans += n-1;
		ans += (n-1)*(n-2) / 2 - k;
		cout << ans << endl;
		REP1(i, n-1) cout << i << " " << n << endl;
		tmp = n - 1;

		REP1(i, n-2){
			REP1(j, n-1){
				if(tmp < ans && i < j){
					cout << i << " " << j << endl;
					tmp++;
				}
			}
		}

	}		
}