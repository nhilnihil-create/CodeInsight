#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;

int main(){	
	string S;
	long long N;
	scanf("%lld",&N);
	cin >> S;
	ll res = 1;
	ll l = 0;
	rep(i, 2*N) {
		if ((l%2 == 0 && S[i] == 'B') || (l%2 == 1 && S[i] == 'W')) {
			l++;
		} else {
			if (l == 0) {
				cout << "0\n";
				return 0;
			}
			res = res*l%mod;
			l--;
		}
	}
	if (l != 0) {
		cout << "0\n";
		return 0;
	}
	repn(i, N) {
		res = res*i%mod;
	}
	cout << res << endl;
	return 0;
}

