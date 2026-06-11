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
	ll t, a, k;
	cin >> t >> a >> k;
	ll r = max(0LL,t-k);
	cout << max(0LL,t-k) << " " << max({0LL, a - (k - t + r)});
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
