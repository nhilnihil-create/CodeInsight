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


ll ans, mx, mn, flag, sum, cnt;


int main(){
	ll n,d;
	cin>>n>>d;
	for(ll i=1; i<=n; i++){
		if(cnt==d*2){
			ans++;
			cnt=0;
		}
		else cnt++;
	}
	if(cnt>0) ans++;
	cout<<ans<<endl;
}
