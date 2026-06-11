#include <bits/stdc++.h>
using namespace std;
#include <cmath>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	vector<ll>a,b;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	for(ll j=0;j<n;j++){
		ll x;
		cin>>x;
		b.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	ll right = 0; 	
	for(ll j=0;j<n;j++){
		right=max(a[j]*b[j],right);
//		cout << a[j]<<" "<<b[j]<<endl;
	}
//	cout <<right<<endl;
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
 // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        ll cnt=0;
        for(ll i=0;i<n;i++){
        	if(a[i]*b[i]>mid){
        		cnt+=a[i]-mid/b[i];
        	}
        }
//        cout <<cnt<<" ";
        if (cnt<=k) right = mid;
        else left = mid;
//    	cout <<mid<<endl;        
    }
    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    cout << max(ll(0),right);	
	// your code goes here
	return 0;
}