#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;


ll check(ll n){ 
    ll count = 0; 
    for (ll i = 5; n / i >= 1; i *= 5) 
        count += n / i; 
    return count; 
} 

int main(){
	ll n;
	cin>>n;
	if(n%2==0){
		ll g=n/10;
		ll h=check(g);
		cout<<g+h<<endl;
	}
	else cout<<0<<endl;
}
