#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;


bool isprime(ll n){
    long double sqr_n=sqrt((long double)n);
    for(ll i=2;i<=sqr_n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(void){
    ll n;
	cin >> n;
	int ans=0;
	for(ll i=2;i*i<=n;i++)
        if(n%i==0){
		    int cnt=0;
		    while(n%i==0)
                n/=i,cnt++;
		    for(int j=1;j<=cnt;j++){
			    cnt-=j;
			    ans++;
		    }
	    }
	if(n!=1)
        ans++;
    cout << ans;
    return 0;
}