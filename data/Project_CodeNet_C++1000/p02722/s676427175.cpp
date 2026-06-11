#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define F first
#define S second

#define ONLINE_JUDGE 1

using namespace std;

const int mod = 1e9+7;

bool check(ll n, ll d){
	while(n%d==0 && d > 1)
		n/=d;
	return n%d==1;
}

ll phi(ll n) {
    ll result = 0;
    for (ll i = 1; i * i <= n; i++) {
       if(n%i==0){
       	if(n/i==i) result++;
       	else result+=2;
       }
    }
    return result;
}

void solve(){
	ll n;
	cin >> n;
	int cnt = 0;
	for(ll i = 2; i * i <= n; i++){
		if(n%i==0){
			if(n/i==i){
				cnt+=check(n,i);
			}else{
				cnt+=check(n,i);
				cnt+=check(n,n/i);
			}
		}
	}
	cnt+= phi(n-1);
	//cout << phi(n-1) << "\n";
	cout << cnt  << "\n";	
}
int main(){
	#ifndef ONLINE_JUDGE	
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL),cout.tie(NULL);		
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}