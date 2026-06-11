#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll e;
int main(){
	while(1) {
		cin >> e;
		if(e == 0) 
			break;


		ll ans = 1000000000000;
		for(ll z = 0;z * z * z <= e;z++) {
			for(ll y = 0; y * y <= e - z * z * z;y++) {
				ll x = e - z * z * z - y * y;
				if(x >= 0) {
					ans = min(ans,x + y + z);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

