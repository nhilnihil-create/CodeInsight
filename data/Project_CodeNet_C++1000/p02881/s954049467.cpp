#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
     ll n ; cin >> n;
     ll ans = 1e13;
     for(ll i =1 ; i*i<=n ; i++){
     	if(n%i==0){
     		ans = min(ans,((i-1)+ ((n/i)-1)));
		 }
	 }
	 cout << ans << endl;
}