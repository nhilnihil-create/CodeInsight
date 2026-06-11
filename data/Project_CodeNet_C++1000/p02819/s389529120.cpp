#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
	ll n;
	cin >> n;
	while(1){
		ll c = 0;
		for(ll i = 2; i * i <= n; i++){
			if(n%i == 0){
				c = 1;
				break;
			}
		}
		if(c)n++;
		else{
			cout << n << nl;
			return;
		}
	}
}

int main(){ 
#ifndef ONLINE_JUDGE
 //   freopen("input1.txt","r",stdin);
  //  freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
     //cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}

