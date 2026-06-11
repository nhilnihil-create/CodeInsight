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
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	if(n < m){
		for(ll i=0; i<m; i++)
			cout << n;
	}
	else
		for(ll i=0; i<n; i++)
			cout << m;
	return 0;
}