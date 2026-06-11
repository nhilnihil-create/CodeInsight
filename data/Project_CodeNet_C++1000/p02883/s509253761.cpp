#include <bits/stdc++.h>
using namespace std;
#include <cmath>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	vector<ll>a;
	vector<ll>f;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		a.push_back(now);
	}
	for(ll j=0;j<n;j++){
		ll now;
		cin>>now;
		f.push_back(now);
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(f.begin(),f.end());
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right =1000000000002; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        ll cnt=0;
        for(ll i=0;i<n;i++){
        	ll now=mid/f[i];
        	cnt+=max(ll(0),a[i]-now);
        }
        if (cnt<=k) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    cout << right;	
	// your code goes here
	return 0;
}