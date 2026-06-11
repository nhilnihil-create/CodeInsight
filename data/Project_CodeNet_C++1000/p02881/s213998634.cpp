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
	const ll INF = 1e17;
	ll minn = INF;
	for(ll i=1; i*i <= n; i++){
		if(n%i == 0){
			minn = min((n/i)+i - 2, minn);
		}
	}
	cout << minn;
	return 0;
}