#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
	ll x;
	cin >> x;

	ll ans[2];	
	for(ll i=-1000;i<=1000;i++){
		for(ll j=i; j<=1000; j++){
			if(j*j*j*j*j - i*i*i*i*i==x){
				ans[0] = j;
				ans[1] = i;
				break;
			}
		}
	}
	cout << ans[0] << " " << ans[1] << endl;
	
	
	
	return 0;
}