#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll ans, mx, sum,temp, mn = 1e14, flag,cnt;

int main(){
	ll n,l;
	cin>>n>>l;
	for(ll i=1; i<=n; i++){
		sum+=l+i-1;
	}
	for(ll i=1; i<=n; i++){
		ll k=l+i-1;
		if(abs(sum-(sum-k))<=mn){
			mx=sum-k;
			mn=abs(sum-(sum-k));
		}
	}
	cout<<mx;
}
