#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll t1,t2,a1,a2,b1,b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	ll diff=a1*t1+a2*t2-b1*t1-b2*t2;
	if(diff==0){
		cout << "infinity\n";
		return 0;
	}
	if(diff<0){
		swap(a1,b1);
		swap(a2,b2);
		diff*=-1;
	}
	if(a1>b1){
		cout << "0\n";
		return 0;
	}
	ll x=b1*t1-a1*t1;
	ll ans=1+2*((x-1)/diff);
	if(x%diff==0) ans++;
	cout << ans << "\n";
	return 0;
}
