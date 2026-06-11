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
	ll ara[n];
	for(int i = 0; i<n; i++){
		scanf("%lld", &ara[i]);
	}
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
	for(int j = 0; j<n; j++){
		for(int i = lim-1; i>=0; i--)
		{
			if(ara[j]&(1ll<<i)){
				if(!basis[i]){
					basis[i] ^= ara[j];
					break;
				}
				ara[j] ^= basis[i];
			}
		}
	}
	
	ll nw = 0;
	for(int i = lim-1; i>=0; i--)
		if(nw < (nw^basis[i])) nw ^= basis[i];
	printf("%lld\n", 2ll*nw+ans);
	return 0;
}