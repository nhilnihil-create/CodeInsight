#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	ll a[m];
	for(ll i=0; i<m; i++){
		cin >> a[i];
		n -= a[i];
	}
	if(n < 0)
		cout << -1;
	else
		cout << n;
	return 0;
}