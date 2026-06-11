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
	ll n;
	cin >> n;
	vector<ll> adjlist[n+1];
	ll x;
	for(ll i=1; i<n; i++){
		cin >> x;
		--x;
		adjlist[x].emplace_back(i);
	}
	for(ll i=0; i<n ;i++)
		cout << adjlist[i].size() << "\n";
	return 0;
}