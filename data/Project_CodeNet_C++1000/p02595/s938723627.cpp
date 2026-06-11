#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
int main(){
	ll n , d;
	cin >> n >> d;
	ll a[n][2],ans=0;
	for(ll i =0;i<n;i++){
	   for(ll j =0;j<2;j++){
		cin >> a[i][j];	   
	   }
	}
	for(ll i=0;i<n;i++){
	   long double x = sqrt( (a[i][0] * a[i][0]) + (a[i][1] * a[i][1] ) );
	   if(d>=x)ans++;
	}
	cout << ans << endl;



	return 0;
}