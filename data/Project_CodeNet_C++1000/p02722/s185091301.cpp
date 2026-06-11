#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T3;

int main(){
	ll n;
	cin >> n;

	ll ans = 1;//nをカウント
	if(n > 2)ans++;//n-1が条件を満たす

	for(ll i = 2;i * i <= (n-1);i++){
		if((n-1) % i == 0){
			if(i * i != (n-1))ans += 2;
			else ans++;
		}
	}

	for(ll i = 2;i * i <= n;i++){
		if(n % i == 0){
			ll now1 = n;
			while(now1 % i == 0)now1 /= i;
			if(now1 % i == 1)ans++;

			if(i * i != n){
				ll now2 = n;
				ll j = n / i;
				while(now2 % j == 0)now2 /= j;
				if(now2 % j == 1)ans++;
			}
		}
	}
	cout << ans << endl;
}
