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

double d;
int main(){
	ll n;
	cin>>n;
	for(ll i=0; i<n; i++){
		double a;
		cin>>a;
		d+=1.0/a;
	}
	cout<<1.0/d;
			
}
