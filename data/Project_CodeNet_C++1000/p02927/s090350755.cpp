#include "bits/stdc++.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Pll;
typedef pair<P,P> PP;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define repr(i,a,n) for(ll i = n-1;i >= a;i--)
#define LINF (ll)1e17
#define INF (int)1e9
#define MOD (ll)1e9+7
#define sMOD 1e5
#define fs first
#define sc second

ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
	
}



signed main(){
	ll m,d,d1,d2,cnt = 0;
	cin >> m >> d;
	
	rep(i,1,d+1){
		d1 = i%10;
		d2 = i/10;
		
		if(d1 >= 2 && d2 >= 2 && d1*d2 >= 1 && d1*d2 <= m){
			cnt++;
		}
	}
	
	cout << cnt << endl;
    return 0;
}