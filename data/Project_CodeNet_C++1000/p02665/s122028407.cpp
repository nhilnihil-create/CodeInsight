#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000000+7)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;

ll npow(ll x,ll power) {
	ll res = 1;
	ll k = power;
	ll y = x;
	while (k) {
		if (k & 1)res = (res*y);
		y = (y*y);
		k /= 2;
	}
	return res;
}

int main(void){
    int n;
    cin>>n;
    vector<ll>a(n+1);
    for(ll i=0;i<=n;i++)cin>>a[i];
    if(n==0){
        if(a[0]==1)cout<<1<<endl;
        else cout<<-1<<endl;
        return 0;
    }
    ll uncon = 0;
    ll p = 1;
    ll d = 1;
    ll ans = 0;
    vector<ll>l(n+1),r(n+1);
    l[n]=a[n],r[n]=a[n];
    for(ll i=n-1;i>=0;i--){
        if(i==0){
            l[i]=(l[i+1]+1)/2+a[i];
            r[i]=r[i+1]+a[i];
            if(1<l[i]){
                cout<<-1<<endl;
                return 0;
            }
        }
        else{
            ll num = (l[i+1]+1)/2;
            l[i]=num+a[i];
            r[i]=a[i]+r[i+1];
        }
    }
    ans = 1;
    ll abv = 1;
    for(ll i=1;i<=n;i++){
        ll now = min(2*abv,r[i]);
        ans+=now;
        abv = now-a[i]; 
    }
    cout<<ans<<endl;
    return 0;
}