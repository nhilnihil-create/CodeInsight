#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 100005
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	ll ara[n+64];
	memset(ara, 0, sizeof ara);

	for(int i = 0; i<n; i++){
		scanf("%lld", &ara[i]);
	}
	if(n < 64) n = 64;
	int lim = 61;
	ll ans = 0;
	for(int i = 0; i<lim; i++){
		int c = 0;
		for(int j = 0; j<n; j++){
			if(ara[j]&(1ll<<i)) c++;
		}
		if(c & 1){
			for(int j = 0; j<n; j++){
				ara[j] = ara[j]&(~(1ll<<i));
			}
			ans |= (1ll << i);
		}
	}
	ll basis[62];
	memset(basis, 0, sizeof basis);
	for(int i = lim-1, k = 0; i>=0; i--, k++){
		for(int j = k; j<n; j++){
			if(ara[j]&(1ll<<i)){
				swap(ara[j], ara[k]);
				break;
			}
		}
		if((ara[k]&(1ll<<i)) == 0) {
			k--;
			continue;
		}
		
		for(int j = 0; j<n; j++){
			if(j != k && (ara[j]&(1ll<<i))){
				ara[j] ^= ara[k];
			}
		}
		// for(int j = 0; j<n; j++){
		// 	cout << k << " " << bitset<5>(ara[j]) << endl;

		// }
		// cout << endl;
		// cout << endl;
	}
	
	ll nw = 0;
	for(int i = 0; i<lim; i++){
		if(nw^(ara[i]) > nw) nw ^= ara[i];
	}
	printf("%lld\n", 2ll*nw+ans);
	return 0;
}