#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <iomanip>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum=1, cnt;

ll idx=1;
int main(){
	ll n,x;
	cin>>n>>x;
	ll d[n+1];
	d[0]=0;
	ll l[n+1];
	l[0]=0;
	for(ll i=1; i<=n; i++){
		cin>>l[i];
	}
	for(ll i=1; i<=n+1; i++){
		d[i]=d[i-1]+l[i-1];
	}
	for(ll i=1; i<=n+1; i++){
		if(d[i]<=x) ans++;
	}
	cout<<ans<<endl;
}
